#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = " << x << endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F; 
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;

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

void initFactorials()
{
  fat[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < maxn; i++)
  {
    fat[i] = (i * fat[i-1]) % mod;
    inv[i] = exp(fat[i], mod - 2);
  }
}

string s;
int findNum(int pos, char c, int inc)
{
  int cnt = 0;
  for(int i = pos; s[i] == c; i += inc)
    cnt++;
  return cnt;
}

int main()
{
  ios::sync_with_stdio(0);
  vector<int>ans;
  cin >> s;
  int n = s.size();
  for(int i = 0 ; i < n ; i++)
  {
    if(i < n - 1 && s[i] == 'R' && s[i + 1] == 'L')
    {
      int numR = findNum(i, 'R', -1);
      int numL = findNum(i + 1, 'L', +1);
      
      ans.push_back(((numR + 1) / 2) + (numL / 2));
      ans.push_back((numR / 2) + ((numL + 1) / 2));
      i++;
    }
    else
    {
      ans.push_back(0);
    }
  }

  for(const auto &c : ans)
    cout << c << ' ';
  cout << endl;

  return 0;
}