#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define initdp(a, b)  for (int i = 0; i <= a; i++)   for (int j = 0; j <= b; j++) dp[i][j] = -1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define inf 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define umapi unordered_map<ll, ll>
#define umapc unordered_map<char, int>
#define endl "\n"
using namespace std;
 
int n,k;
vec arr(2000005);

int check (int x) {
    int ans = 0;
    rep(i,n) {
        if(arr[i] <=x) {
            continue;
        }
        ans+= arr[i]/x;
    }

    return ans<=k;
}

void solve()
{
    cin>>n>>k;

    
    rep(i,n) {
        cin>>arr[i];
    }

    int l = 1, r= 1e9;
    int ans;
    while(l<=r) {
        int m = mid(l,r);
        if(check(m)) {
            ans = m;
            r= m-1;
        } else {
            l= m+1;
        }
    }

    cout<<ans<<endl;
    
    
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
  //  cin >> t;
    while (t--)
    {
        solve();
    }
}