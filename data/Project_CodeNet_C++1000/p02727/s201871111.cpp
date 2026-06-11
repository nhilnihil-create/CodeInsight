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


ll p[maxn], q[maxn], r[maxn];

int main()
{
  ios::sync_with_stdio(false);
  int a,b,c,x,y;
  cin >> x >> y >> a >> b >> c;
  
  for(int i = 0; i < a; i++)
  {
    cin >> p[i];
  }

  for(int i = 0; i < b; i++)
  {
    cin >> q[i];
  }

  for(int i = 0; i < c; i++)
  {
    cin >> r[i];
  }

  sort(p, p + a);
  sort(q, q + b);
  sort(r, r + c, greater<ll>());

  ll sumP = 0, sumQ = 0;

  for(int i = 0, j = a - 1; i < x; i++, j--)
    sumP += p[j];


  for(int i = 0, j = b - 1; i < y; i++, j--)
    sumQ += q[j];


  int pp = a - x, pq = b - y, pr = 0;



  ll ans = sumP + sumQ;

  //debug(ans);

  while(pr < c)
  {
    if(pp == a || pq == b)
      break;
    ll val = 0;
    if(-p[pp] > -q[pq])
    {
      val = sumP - p[pp] + r[pr] + sumQ;
      //debug(val);
      sumP -= p[pp];
      sumP += r[pr]; 
      pp++;
    }
    else
    {
      //debug(q[pq]);
      val = sumQ - q[pq] + r[pr] + sumP;
      sumQ -= q[pq];
      sumQ += r[pr]; 
      pq++;
    }
    //cout << val << endl;    
    if(val > ans)
    {
      ans = val;
    }
    else
      break;
    
    pr++;
  }


  ll val = 0;
  while(pr < c && pp < a && (sumP - p[pp] + r[pr] + sumQ > ans))
  {
    val = sumP - p[pp] + r[pr] + sumQ;
    sumP -= p[pp];
    sumP += r[pr]; 
    pp++;
    pr++;
    ans = val;
  }


  while(pr < c && pq < b && (sumQ - q[pq] + r[pr] + sumP > ans))
  {
    val = sumQ - q[pq] + r[pr] + sumP;
    sumQ -= q[pq];
    sumQ += r[pr]; 
    pq++;
    ans = val;
    pr++;
  }

  cout << ans << endl;

  return 0;
}