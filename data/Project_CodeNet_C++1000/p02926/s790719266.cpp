#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;

    vector<pair<double, pair<double,double>>> v;
    rep(i,n){
        double x, y;
        cin >> x >> y;
        pair<double, pair<double,double>> p;
        p.first = atan2(y, x);
        p.second.first = x;
        p.second.second = y;
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    rep(i,n){
        v.push_back(v[i]);
    }

    double ans = 0;

    rep(i,n){
        srep(j, 1, n+1){
            ll tmpx = 0;
            ll tmpy = 0;
            rep(k,j){
                tmpx += v[i+k].second.first;
                tmpy += v[i+k].second.second;
            }
            ans = max(ans, sqrt(tmpx*tmpx + tmpy*tmpy));
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
 
 
