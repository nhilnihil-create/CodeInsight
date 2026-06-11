#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<deque>
#define pi 3.1415926535
#include<chrono>
#define float double
#define floa float
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>(temp)
#define f1 get<1>(temp)
#define f2 get<2>(temp)
using namespace std;
ll ncr(ll n, ll r)
{
    ll i, ans = 1, k = 0;
    if (r == 0)
        return 1;
    else if (n < r)
        return 0;
    for (i = n; i >= n - r + 1; i--)
    {
        ans *= i;
        ans /= n - i + 1;
    }


    return ans;

}
bool visited[6] = { false };
int n = 6;
vector<int> adj[6];


void max_heapify(int a[100], int i)
{
    int l, r, largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l<n && a[l]>a[i])
        largest = l;
    if (r<n && a[r]>a[l])
        largest = r;
    if (largest != i)
    {
        int k;
        k = a[i];
        a[i] = a[largest];
        a[largest] = k;
        max_heapify(a, largest);
    }

}
int power(ll x, ll y, ll p)
{
    int res = 1;
    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;


        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

bool square(ll n)
{
    double x;
    x = sqrt(n);
    if (x == floor(x))
        return true;
    else return false;
}


bool prime(ll n)
{
    ll i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll modi(ll a, ll m)
{
    return power(a, m - 2, m);

}
void kmp(string s, ll p[]) {
    int n = (int)s.length();
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }

}
void zfunc(string s, ll z[]) {

    ll n = (ll)s.length();
    z[0] = 0;
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }


}
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<ll>() ((((ll)p.first) << 32) | ((ll)p.second));
    }
};

bool palin(string s) {
    ll i, n;
    n = s.length();
    for (i = 0; i <= n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}
ll sum(ll n) {
    ll i;
    i = n;
    ll sum = 0;
    while (i > 0) {
        sum += i % 10;
        i = i / 10;
    }
    return sum;
}

ll nCr(ll n, ll r, ll p, ll fac[])
{

    if (r == 0)
        return 1;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;

    return (fac[n] * modi(fac[r], p) % p *
        modi(fac[n - r], p) % p) % p;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void bfs(vector<ll>& ans, ll k) {
    queue<ll> q;

    while (!q.empty()) {
        ll temp = q.front();

    }
}

void solve(ll l, ll r) {
    if (l >= r) {
        return;
    }
    if ((r - l) % 2 == 1) {
        ll start = (r + l) / 2 + 1;
        ll k = -1, j = 1;
        while (start != l) {

            printf("%lld %lld\n", start, start + k * j);
            //cout <<start <<" "<< start + k * j << endl;
            if (start + k * j == l) {
                break;
            }
            start += k * j;
            j++;
            k *= -1;

        }
    }
    else {
        ll start = (r + l) / 2;
        ll k = 1, j = 1;
        while (start != l) {

            printf("%lld %lld\n", start, start + k * j);
            //cout << start << " " << start + k * j << endl;
            if (start + k * j == l) {
                break;
            }
            start += k * j;
            j++;
            k *= -1;

        }
    }
}


void dfs(ll start, vector<ll> adj[], bool visited[], ll dp[], ll& maxi) {
    visited[start] = true;

    for (auto u : adj[start]) {
        if (!visited[u]) {
            visited[u] = true;
            dp[u] = max(dp[u], dp[start] + 1);
            dfs(u, adj, visited, dp, maxi);
            maxi = max(maxi, dp[u]);
        }

    }
}
float fab(float x) {
    if (x < 0) {
        return -x;
    }
    return x;
}
ll f(ll x, vector<ll> &v,ll n,ll s) {
    ll cnt = 0;
    for (ll k = 0; k < n / 2; k++) {
        ll num = v[k] + v[n - k - 1];
        if (num == x) {
            continue;
        }
        ll maxsum, minsum;
        maxsum = max(v[k], v[n - k - 1]) + s;
        minsum = min(v[k], v[n - k - 1]) + 1;
        if (x >= minsum && x <= maxsum) {
            cnt++;
        }
        else {
            cnt += 2;
        }
    }
    return cnt;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll T = 1, i, j;
    //cin >> T;
 
    while (T--) {
        ll n, k;
        cin >> n >> k;
        if (k > (n - 1)* (n - 2) / 2) {
            cout << "-1";
        }
        else {
            cout << n - 1 + ((n - 1 ) * (n - 2 )/ 2 - k)<< endl;
            for (i = 2; i <= n; i++) {
                cout << 1 << " " << i << endl;
             }
      
         
            ll ans = (n - 1) * (n - 2) / 2;
            for (i = 2; i <= n; i++) {
                for (j = i + 1; j <= n; j++) {
                    if (ans - k > 0) {
                        cout << i << " " << j << endl;
                        ans--;
                    }
                    if (ans - k == 0) {
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
