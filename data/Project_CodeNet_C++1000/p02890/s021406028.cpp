#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//clock_t start=clock();clock_t end=clock();cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1LL<<60;
double pi=3.141592653589793238462643383279L;
double eps=1e-10;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
#define srep(itr,st) for(auto itr=st.begin();itr!=st.end();itr++)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k,ll md){
  ll ret=1;
  ll now=n;
  while(k>0){
    if(k%2==1){
      ret*=now;
      ret%=md;
    }
    now*=now;
    now%=md;
    k/=2;
  }
  return ret;
}
ll gyaku(ll n,ll md){
  return beki(n,md-2,md);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int a[n];
    int cnt[n+1];
    fill(cnt,cnt+n+1,0);
    rep(i,0,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int> v;
    rep(i,1,n+1){
        if(cnt[i]>0)v.push_back(cnt[i]);
    }
    sort(v.begin(),v.end());
    int ans[n+1];
    fill(ans,ans+n+1,-1);
    int sum=0;
    int num=0;
    int sa[n+1];
    sa[0]=n;
    rep(i,1,n+1){
        while(num<v.size()&&v[num]==i){
            sum+=i;
            num++;
        }
        int ss=sum+(v.size()-num)*i;
        sa[i]=ss/i;
        rrep(j,sa[i-1],sa[i]+1)ans[j]=i-1;
    }
    ans[1]=n;
    rep(i,1,n+1)cout<<ans[i]<<endl;
}



