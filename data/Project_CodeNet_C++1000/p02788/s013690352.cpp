#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,d,a;cin>>n>>d>>a;d*=2;
    vector<pair<ll,ll>> p(n);
    rep(i,n) cin>>p[i].first>>p[i].second;
    sort(p.begin(),p.end());
    ll dam=0;
    queue<pair<ll,ll>> que;
    ll res=0;
    rep(i,n){
        ll x=p[i].first,h=p[i].second;
        while(que.size()){
            ll x1=que.front().first,h1=que.front().second;
            if(x1<x-d){
                dam-=h1;
                que.pop();
            }else break;
        }
        h-=dam;
        if(h<=0)continue;
        ll tmp=(h+a-1)/a;
        res+=tmp;
        que.push({x,tmp*a});
        dam+=tmp*a;
    }
    cout<<res<<endl;
}