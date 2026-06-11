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
#define PB pop_back
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;




void solve(){
    string s, t;
    int ans = 0;
    cin>>s>>t;
    f(i,3){
        if(s[i] == t[i])ans++;
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
