#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
int main(){
    int n,q=0;cin>>n;
    string s;cin>>s;
    rep(i,n*2){
        ll p=0;
        if(s[i]=='B')p=1;
        if((i%2+p)==1){
            s[i]='L';
            q++;
        }
        else s[i]='R';
    }
    ll ans=1;
    if(q!=n)ans=0;
    ll k=0;
    rep(i,n*2){
        if(s[i]=='L')k++;
        else {
            ans*=k;
          	ans%=mod;
            k--;
        }
    }
  	rep(i,n)ans=ans*(i+1)%mod;
    cout<<ans<<endl;
}