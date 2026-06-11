#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 1;
vector<int> g[N];
void solve(){
    string s;
    cin >> s;
    string s1 = "s", s2 = "es";
    cout << (s[(int)s.size() - 1] == 's' ? s + s2 : s + s1) << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        solve();
    }
}