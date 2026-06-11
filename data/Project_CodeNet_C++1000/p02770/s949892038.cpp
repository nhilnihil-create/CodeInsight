#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
string alp="abcdefghijklmnopqrstuvwxyz";
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){
    ll k,q;cin>>k>>q;
    ll d[k];rep(i,0,k-1)cin>>d[i];
    ll n[q],x[q],m[q];rep(i,0,q-1)cin>>n[i]>>x[i]>>m[i];
    ll amari[k];
    ll sum[5010];
    ll c[5010];
    ll l,r;
    rep(i,0,q-1){
        sum[0]=x[i];
        l=x[i];
        c[0]=0;
        rep(j,0,k-1){
            amari[j]=d[j]%m[i];
            sum[j+1]=sum[j]+amari[j];
            if(amari[j]==0){
                c[j+1]=c[j]+1;
            }else{
                c[j+1]=c[j];
            }
        }
        r=x[i]+(sum[k]-sum[0])*((n[i]-1)/k)+(sum[(n[i]-1)%k]-sum[0]);
        cout<<(n[i]-1)-((r/m[i])-(l/m[i]))-(c[k]*((n[i]-1)/k)+c[(n[i]-1)%k])<<endl;
        
        
    }
    
    
    return 0;
}

