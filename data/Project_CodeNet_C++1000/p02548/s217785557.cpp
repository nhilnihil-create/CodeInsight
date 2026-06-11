#include <bits/stdc++.h>

#define Khaled ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lli long long int
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define dbg(x) cout << x << endl
#define FOR(i, n) for (i = 0; i < n; i++)
#define FO(i,k,n) for(i = k; i <= n; i++)
#define in(v) for(auto &it : v) cin >> it;
#define out(v) for(auto it : v) cout << it << ' '; cout << endl;
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()
#define PI acos(-1)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define MAX 100005
 
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;

string let = "abcdefghijklmnopqrstuvwxyz";

void solve()
{
    lli i, j, n, m, a, b, c, d, x, y, z, k, l;
    cin >> n;
    a = 1;
    lli ans = 0;

    FO(i,1,n-1) {
        ans += ((n-1) / i);
    }
    dbg(ans);
    
    return;
}

int main()
{
    Khaled
    // freopen("input", "r", stdin);
    // freopen("output" , "w" , stdout);
    int t = 1,i;
    // cin >> t;
    FO(i,1,t) {
        solve();
    }

    return 0;
}