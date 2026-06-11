#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 1000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll bigmod(ll a,ll b){
   if(b==0) return 1%mod;
   ll x=bigmod(a,b/2);
   x=(x*x)%mod;
   if(b%2) x=(x*a)%mod;
   return x;
}

int main(){
    FASTIO
    ll n,tot,sub,add,ans;
    cin>>n;
    tot=bigmod(10,n);
    add=bigmod(8,n);
    sub=bigmod(9,n);
    sub=(2*sub)%mod;
    ans=(tot-sub+add+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
