#include<bits/stdc++.h>
using namespace std;
#define fast                                                                   \
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ff(i, n) for (int i = 1; i <= n; i++)
#define F first
#define S second
#define vpii vector<pair<int,int> >
#define sz size()
#define all(v) v.begin(),v.end()
#define pb push_back   
#define PB pop_back
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;





void solve(){
    int n, ans = 0;
    cin>>n;
    int a[n+5], b[n+5], c[n+5];
    ff(i,n)cin>>a[i];
    ff(i,n)cin>>b[i];
    ff(i,n-1)cin>>c[i];
    a[0] = a[n+1] = 123456789;
    ff(i,n)ans += b[i];
    ff(i,n-1)if(a[i] + 1 == a[i+1])ans += c[a[i]];
    cout<<ans;
}

int32_t main() {
    fast
    int t;
    t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
