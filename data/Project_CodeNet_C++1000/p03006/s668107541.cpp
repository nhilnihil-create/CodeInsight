//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    map<pair<ll,ll>,ll> cnt;
    vector<pair<ll,ll>> b(n);
    rep(i,n){
        ll x,y; cin>>x>>y;
        b[i]=mk(x,y);
    } 
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(i==j) continue;
        ll dx=b[i].first-b[j].first;
        ll dy=b[i].second-b[j].second;
        if(!(cnt.count(mk(dx,dy)))) cnt[mk(dx,dy)]=0;
        cnt[mk(dx,dy)]++;
    }
    ll maxcnt=0;
    for(auto q:cnt){
        maxcnt=max(maxcnt,q.second);
    }
    cout<<n-maxcnt<<endl;
}