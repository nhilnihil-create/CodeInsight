#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,m;cin >>n>>m;
    vector<P>p(n);
    for (int i = 0; i < n; ++i) {
        ll a,b;cin >>a>>b;
        p[i]={a,b};
    }
    sort(all(p));
    priority_queue<ll>que;
    ll ans=0;
    ll k=0;
    for (int i = 1; i <=m; ++i) {
            while(k<n&&p[k].first<=i) {
                que.push(p[k].second);
                k++;
            }
        if(!que.empty()) {
            ll u = que.top();
            que.pop();
//            cout <<u<<endl;
            ans += u;
        }
    }
    cout <<ans <<endl;
    return 0;
}
