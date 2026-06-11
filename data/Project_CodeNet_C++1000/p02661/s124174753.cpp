#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define REP(i,x,y) for(ll i = x;i <= y;++i)
vector<string> vec_splitter(string s) {
    for(char& c: s) c = c == ','?  ' ': c;
    stringstream ss; ss << s;
    vector<string> res;
    for(string z; ss >> z; res.push_back(z))
        ;
    return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
    if(idx > 0) cerr << ", ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __VA_ARGS__)
void localTest() {
    #ifndef ONLINE_JUDGE
        freopen("inp", "r", stdin);
        freopen("out", "w", stdout);
    #endif      
}
const ll N = 2e5 + 5;
ll A[N], B[N];
int main() {

    localTest();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, ans = 0, l, r;
    cin >> n;
    for(ll i = 1;i <= n;++i) cin >> A[i] >> B[i]; 
    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + n);
    if(n & 1) l = A[(n + 1) / 2], r = B[(n + 1) / 2];
    else l = A[n / 2] + A[n / 2 + 1], r = B[n / 2] + B[n / 2 + 1];
    ans = r - l + 1;
    cout << ans << "\n";
    
    return 0;
}