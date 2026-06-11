                     //  @ /\/\ BESH //

#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back
#define FILE freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);


using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1000001;
const int mod = 1000000007;

ll fac[MAXN];
ll inv[MAXN];

ll modPower(ll x,ll y){
    x%=mod;
    ll res = 1;
    while(y){
        if(y&1)res= (res*x)%mod;
        x = (x*x)%mod;
        y>>=1;
    }
    return res;
}

void pre(){
    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)fac[i] = (i * fac[i-1])%mod;
    inv[MAXN-1] = modPower(fac[MAXN-1] , mod-2);
    for(ll i = MAXN-2; i >= 0; i--)inv[i] = (inv[i+1] * (i+1))%mod;
}

ll nCr(ll n, ll r){
    if(r > n)return 0;
    return fac[n] * (inv[r] * inv[n-r] % mod) % mod;
}


int main(){
    int n;
    cin>>n;
    string s[n];
    int t[n];
    fr(i,n){
        cin>>s[i]>>t[i];
    }
    string x;
    cin>>x;
    int ans = 0;
    bool found = 0;

    fr(i,n){
        if(found)ans += t[i];
        else if(s[i] == x)found = 1;
    }

    cout<< ans << endl;

}
