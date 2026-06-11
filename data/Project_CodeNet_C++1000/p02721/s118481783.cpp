  #include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cout << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;
const ll mod = 1e9 + 7;

inline int cmp(double x, double y = 0) 
{  
  if(fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

ll exp(ll a, ll b)
{
  ll ans = 1;
  while(b)
  {
    if(b & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

const int maxn = 2e5 + 10;
ll fat[maxn], inv[maxn];

ll C(int n, int k)
{
  if(n < k) 
    return 0;
  if(n < 0 || k < 0) 
    return 0;
  return (((fat[n] * inv[k]) % mod) * inv[n - k]) % mod;
}


bool has[maxn];

int main()
{
  ios::sync_with_stdio(false);
  int n, k, c;
  string s;
  int cnt = 0;
  cin >> n >> k >> c >> s;
  for(int i = 0; i < n ; i++)
  {
    if(s[i] == 'o')
    {
      has[i] = true;
      i += c;
      cnt++;
    }
  }
  
  if(cnt !=  k)
    return 0;

  vector<int>ans;

  for(int i = n-1 ; i >= 0 ; i--)
  {
    if(s[i] == 'o')
    {
      if(has[i] == true)
      {
        ans.push_back(i);
      }
      i -= c;
    }
  }

  reverse(all(ans));

  for(const auto &c : ans)
    cout << c + 1 << endl;
  
  
  return 0;
}