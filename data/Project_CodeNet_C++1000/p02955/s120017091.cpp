#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    ll n,k;cin>>n>>k;
    vl a(n);rep(i,n)cin>>a[i];
    ll sum=0;
    rep(i,n) sum+=a[i];
    vl div;
    for(ll i=1;i*i<=sum;i++){
        if(sum%i==0) div.push_back(i);
        if(sum%i==0&&i!=sum/i) div.push_back(sum/i);
    }
    sort(div.rbegin(),div.rend());
    rep(i,(int)div.size()){
        ll mcnt=0,pcnt=0;
        vl num;
        rep(j,n){
            ll cnt=a[j]/div[i];
            ll need=a[j]-div[i]*cnt;
            num.push_back(need);
        }
        sort(num.begin(),num.end());
        ll idx=0;
        while(mcnt+num[idx]<=k&&idx<(int)num.size()){
            mcnt+=num[idx];
            idx++;
        } 
        for(int j=idx;j<(int)num.size();j++) pcnt+=div[i]-num[j];
        if(mcnt>=pcnt){
            cout<<div[i]<<endl;
            return 0;
        }
    }
    return 0;
}