#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 100009 /// I wanna be the wind
#define MOD 1000000007
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
const int N = 10000000;
int lp[N+1];
vector<int> pr;
ll ans[N+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 

    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    ll n;
    cin>>n;
    ll anst=0;
    rep(i,1,n+1){
        if(i==1)ans[1]=1;
        else if(lp[i]==0)ans[i]=2;
        else{
            ll calc = i/lp[i];
            ll cont=0;
            while(calc%lp[i]==0){
                calc/=lp[i];
                cont++;
            }
            ans[i] = (ans[i/lp[i]]/(cont+1))*(cont+2);
        }
        anst+=i*ans[i];
    } 
    cout<<anst<<'\n';
    return 0;  
}