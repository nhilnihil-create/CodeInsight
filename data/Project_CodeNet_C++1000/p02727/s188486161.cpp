/**
*    author:  souzai32
*    created: 13.08.2020 15:01:26
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    long long x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a),q(b),r(c);
    rep(i,a) cin >> p.at(i);
    rep(i,b) cin >> q.at(i);
    rep(i,c) cin >> r.at(i);

    sort(p.begin(),p.end(),greater<>());
    sort(q.begin(),q.end(),greater<>());
    sort(r.begin(),r.end(),greater<>());

    long long ans=0;
    rep(i,x) ans+=p.at(i);
    rep(i,y) ans+=q.at(i);
    // cout << ans << endl;

    x--; y--;
    int xmin=p.at(x),ymin=q.at(y),num;
    // cout << xmin << ' ' << ymin << endl;
    int i=0;
    while(true){
        if(xmin>ymin){
            num=ymin;
            y--;
            if(y<0) ymin=1e9;
            else ymin=q.at(y);
        }
        else{
            num=xmin;
            x--;
            if(x<0) xmin=1e9;
            else xmin=p.at(x);
        }

        // cout << num << ' ' << i << ' '<< r.at(i) << endl;

        if(r.at(i)>num){
            ans+=r.at(i)-num;
            i++;
            // cout << ans << endl;
            // cout << num << endl;
            // cout << r.at(i-1) << endl;
        }
        else break;
        if(i==c) break;
        if(x<0&&y<0) break;
    }

    cout << ans << endl;

    return 0;
}