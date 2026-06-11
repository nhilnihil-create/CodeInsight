#include <bits/stdc++.h>
using namespace std;
#define fast                                                                   \
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ff(i, n) for (int i = 1; i <= n; i++)
#define F first
#define S second
#define pii pair<int,int>
#define sz size()
#define all(v) v.begin(),v.end()
#define pb push_back
#define pf push_front    
#define PB pop_back
#define pll pair<long long, long long>
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;


void solve(){
    int n, ans = 0;
    cin>>n;
    int a[n+4];
    f(i,n)cin>>a[i];
    f(i,n-1){
        for(int j = i + 1; j < n; j++)ans += (a[i] * a[j]);
    }
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
