#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    vector<ll>b(n+1);
    rep(i,n+1){
        ll k=i;
        ll cnt=0;
        while(k>=2){
            cnt+=k/2;
            k/=2;
        }
        b[i]=cnt;
    }
    vector<ll>a(n);
    rep(i,n){
        char s;cin>>s;
        a[i]=s-'0';
    }
    vector<ll>c(n-1);
    vector<ll>st(3);
    rep(i,n-1){
        c[i]=abs(a[i]-a[i+1]);
        st[c[i]]++;
    }
    if(n==2){
        cout<<c[0]<<endl;
        return 0;
    }
    if(st[1]){
        ll ans=0;
        rep(i,n-1){
            if((b[n-2]-b[i]-b[n-i-2])==0&&c[i]==1)ans+=1;
            //cout<<b[n-2]-b[i]-b[n-i-2]<<endl;
            ans%=2;
        }
        cout<<ans<<endl;
    }else{
        ll ans=0;
        rep(i,n-1){
            if((b[n-2]-b[i]-b[n-i-2])==0&&c[i]==2)ans+=1;
            ans%=2;
        }
        ans%=2;
        cout<<ans*2<<endl;
    }
}