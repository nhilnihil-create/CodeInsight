#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,d,a;cin>>n>>d>>a;
    vector<pair<ll,ll>> p(n);
    rep(i,n) cin>>p[i].first>>p[i].second;
    sort(p.begin(),p.end());
    ll cnt=0,dmg=0;
    queue<pair<ll,ll>> que;
    rep(i,n){
        ll x=p[i].first,h=p[i].second;
        while(que.size()){
            ll b=que.front().first,c=que.front().second;
            if(b>=x)break;
            que.pop();
            dmg-=c;
        }
        h-=dmg;
        if(h<=0)continue;
        ll tmp=(h+a-1)/a;
        cnt+=tmp;
        tmp*=a;
        dmg+=tmp;
        que.push({x+d*2,tmp});
    }
    cout<<cnt<<endl;
}