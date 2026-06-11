#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
vi f(N);
int bp(int pow, int ml){
    int res = 1;
    while(pow){
        if(pow%2)res=(res*ml)%mod;
        ml=(ml*ml)%mod;
        pow/=2;
    }
    res%=mod;
    return res;
}
int A1(int n, int k){
    int res = 1;
    for(int i = n-k+1; i <= n; i++){
        res%=mod;
        res=(res*i)%mod;
    }
    res%=mod;
    return res;
}
int C(int n, int k){
    int res = 1;
    for(int i = 1; i <= k; i++){
        res%=mod;
        res=(res*i)%mod;
    }
    return (A1(n, k)*bp(mod-2, res))%mod;
}
void solve(){
    int n, a, b;
    cin>>n>>a>>b;
    int ans = bp(n, 2);
    ans+=5ll*mod;
    ans--;
    ans-=C(n, a);
    ans-=C(n, b);
    ans%=mod;
    cout<<ans;
}   
signed main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)solve();
}