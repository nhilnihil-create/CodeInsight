    #include<bits/stdc++.h>
    #define pi acos(-1)
    #define ll long long
    #define pii pair<ll,ll>
    #define debug(a) cout<<a<<'\n'
    #define maxn 3009 /// leave to tomorrow anything that can be done today
    #define MOD 998244353
    #define F first
    #define S second
    #define rep(i, a, b) for(ll i = a; i < (b); ++i)
    #define per(i, b, a) for(ll i = b-1; i>=a ; i--)
    #define trav(a, x) for(auto& a : x)
    #define allin(a , x) for(auto a : x)
    #define all(x) begin(x), end(x)
    #define sz(x) (ll)(x).size()
    using namespace std;
    const ll INF = 1e17 + 9;
    ll dp[maxn][maxn]; ///soma i tamanho j
    ll mult(ll a,ll b){
        return a*b%MOD;
    }
    ll fastpow(ll a, ll b){
        ll calc=1;
        for(;b>=1LL;b/=2LL){
            if((b&1LL))calc=mult(calc,a);
            a=mult(a,a);
        }
        return calc;
    }
    ll soma(ll a,ll b){
        if(a+b>MOD)return a+b-MOD;
        else return a+b;
    }
    ll subt(ll a,ll b){
        if(a-b<0)return a-b+MOD;
        else return a-b;
    }
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n,s;
        cin>>n>>s;
        ll vet[maxn];
        rep(i,1,n+1){
            cin>>vet[i];
        }
        rep(i,0,n){
            dp[i][0]=fastpow(2,n);
        }
        // dp[0][0] = fastpow(2,n);
        rep(j,1,n+1){/// caras
            rep(i,1,s+1){//soma 
                if(vet[j]<=i)dp[j][i] = soma(mult(dp[j-1][i-vet[j]],(fastpow(2,MOD-2))),dp[j-1][i]);
                else dp[j][i] = dp[j-1][i];
            }
        }
        // cout<<dp[1][4]<<endl;
        cout<<dp[n][s]<<'\n';
        return 0;   
    }   