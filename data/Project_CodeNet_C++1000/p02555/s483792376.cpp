#include <bits/stdc++.h>
#define FIXED_FLOAT(x)  std::fixed <<std::setprecision(7)<<(x)
#define all(v) (v).begin(), (v).end()
using namespace  std;
#define loop(i,a,b) for (int i=a; i<b; ++i)
using ll = long long;
const int mod = 1e9 + 7;
typedef pair<int , int> pairs;
typedef complex<ll> G;
 
const int N = 1e3 + 10;
 
int power(int a,int b){
    if(!b)
        return 1;
    int c=power(a,b/2);
    c=(1LL*c*c)%mod;
    if(b%2)
        c=(1LL*c*a)%mod;
    return c;
}
 
vector<int>dis(N);
vector<bool>vis(N);
vector<int>c[N];
int far;
int ans;
int now;
void aff(int s, int e, int d) {
    if(vis[s])return;
    vis[s] = true;
    dis[s] = d;
    ans = max(ans, dis[s]);
    for(auto u : c[s]) {
        if(u == e)continue;
        aff(u, s, d + 1);
    }
}
void dfs(int s, int e, int d) {
 
    if(vis[s])return;
 
    dis[s] = d;
    if(now < d) {
        far = s;
        now = d;
    }
    vis[s] = true;
    for(auto u : c[s]) {
        if(u == e)continue;
        dfs(u, s, d + 1);
    }
}
void done() {
    int n;
    cin >> n;
    for(int i = 1;i < n;++i) {
        int a,b;
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    far = 0;
    now = 0;
    ans = 0;
    dfs(1, 0, 0);
 
    fill(vis.begin(), vis.end(), 0);
    fill(dis.begin(), dis.end(), 0);
    aff(far, 0, 0);
    cout << ans * 3 << '\n';
 
}
/*string solve_palindrome(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    //a = s + "#" + a;
    int c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}
*/
 
/*3
3 7 7 9 11
4 6 6 7*/
void solve()
{
    int s;
    cin >> s;
    vector<ll>dp(s + 1, 0);
    if(s < 3) {
        cout << 0 << '\n';
        return;
    }
    dp[3] = 1;
    for(int i = 4;i <= s;++i)
        dp[i] = (dp[i-1] + dp[i-3]) % mod;
    cout << dp[s] << '\n';
 
 
}
int cal(int  n) {
    string s = to_string(n);
    int ans = 0;
    for(int i = 0;i < s.size();++i) {
        ans += s[i] - '0';
    }
    return ans;
}
int sum(long long n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
long long  a[N];
long long  find(int x,int y)
{
    if(x>y) return 1;
    long long ans = 1ll * pow(a[x],find(x+1,y));
    return ans;
}
void another() {
    int n;
    cin >> n;
    vector<int>dp(N + 10, (int)1073709056), a(n + 10);
    for(int i = 0;i < n;++i) {
        cin >> a[i];
    }
    for(int i = n;i < n + 5;++i) {
        a[i] = 0;
    }
    dp[0] = 0;
    for(int i = 0;i < n;++i) {
        dp[i + 2] = min(dp[i + 2], dp[i] + a[i]);
        dp[i + 3] = min(dp[i + 4], dp[i] + a[i]);
        dp[i + 4] = min(dp[i + 4], dp[i] + a[i] + a[i + 1]);
    }
    cout << dp[n] << '\n';
 
 
 
}
 
 
void test_case() {
    int t;
    cin >> t;
    while(t--)another();
}
int main() {
 
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
 
    solve();
}