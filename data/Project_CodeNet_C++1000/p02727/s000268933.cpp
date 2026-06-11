#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector <ll> p(a),q(b),r(c);
    rep(i,a){
        cin >> p[i];
    }
    rep(i,b){
        cin >> q[i];
    }
    rep(i,c){
        cin >> r[i];
    }
    
    sort(p.rbegin(),p.rend());
    sort(q.rbegin(),q.rend());
    sort(r.rbegin(),r.rend());

    vector <ll> ans;
    

    rep(i,x){
        ans.push_back(p[i]);
    }
    rep(i,y){
        ans.push_back(q[i]);
    }

    

    ll kk=0,k=0;
    sort(ans.begin(),ans.end());
    while(r[k]>ans[kk]){
        ans[kk]=r[k];
        ++kk;
        ++k;
    }

    ll ans2=0;
    rep(i,x+y){
        ans2+=ans[i];
    }

    cout << ans2 << endl;





    

    

    

    return 0;
}