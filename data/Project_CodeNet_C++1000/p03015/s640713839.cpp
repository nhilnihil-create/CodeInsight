#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define MOD2 998244353
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
auto clk=clock();
 
ll mexp(ll a, ll b, ll m){
    ll ans=1;
    a%=m;
    while(b){
        if(b&1) ans=ans*a%m;
        b>>=1;
        a=a*a%m;
    }
    return ans;
}

const int N = 100005;

ll dp1[N]; // a + b < L
ll dp2[N]; // a + b = L

int main(){
    IOS
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());


    string s;
    cin >> s;
    int n = s.length();
    dp1[0] = 0, dp2[0] = 1;
    FOR(i,0,n-1){
        if(s[i] == '0'){
            dp1[i+1] = (3 * dp1[i]) % MOD;
            dp2[i+1] = dp2[i];
        }
        else{
            dp1[i+1] = (3 * dp1[i] + dp2[i]) % MOD;
            dp2[i+1] = (2 * dp2[i]) % MOD;
        }
    }
    cout << (dp1[n] + dp2[n]) % MOD;

    cerr<<endl<<endl<<"Time: "<<fixed<<setprecision(12)<<(long double)(clock()-clk)/CLOCKS_PER_SEC<<" ms"<<endl<<endl;
 
    return 0;
}