#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define fast                                                                   \
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i,a,n) for (i = a; i <= n; i++)
#define F first
#define S second
#define pii pair<int,int>
#define sz size()
#define all(v) v.begin(),v.end()
#define pb push_back
#define pf push_front    
#define PB pop_back
#define pll pair<long long, long long>
#define vi vector<int>
#define vl vector<int>
#define mp make_pair
#define mod 1000000007
typedef unsigned long long ull;
const int N = 200005;
const int MOD = 998244353 ;


void solve(){
    int x, y, a, b, c, j = 0, k = 0;
    cin>>x>>y>>a>>b>>c;
    vl v1(a), v2(b), v3(c), ans;
    f(i,a)cin>>v1[i];
    f(i,b)cin>>v2[i];
    f(i,c)cin>>v3[i];
    sort(all(v1));
    reverse(all(v1));
    sort(all(v3));
    reverse(all(v3));
    sort(all(v2));
    reverse(all(v2));
    f(i,x)ans.pb(v1[i]);
    f(i,y)ans.pb(v2[i]);
    sort(all(ans));
    while(j < c && k < ans.size() && v3[j] > ans[k])ans[k++] = v3[j++];
    k = 0;
    f(i,ans.size())k += ans[i];
    cout<<k; 
}

int32_t main() {
    fast
    int t;
    t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
