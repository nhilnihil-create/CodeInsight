#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)
#define R1(a) do{scanf("%d", &(a));}while(0)
#define R2(a, b) do{scanf("%d%d", &(a), &(b));}while(0)
#define R3(a, b, c) do{scanf("%d%d%d", &(a), &(b), &(c));}while(0)
#define SV(vec) do{int s_v_;scanf("%d", &(s_v_));vec.PB(s_v_);}while(0)
#define MM(co, cim) memset((co), (cim), sizeof((co)))
#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;
#define INF 1000000007

#define MOD INF

ll powermod (ll B, ll P, ll M)
{
  ll r = 1;
  if (B >= M) B %= M;
  while (P > 0)
  {
    if ((P & 1) == 1)
    {
      r *= B;
      if (r >= M) r %= M;
    }
    P >>= 1;
    B *= B;
    if (B >= M) B %= M;
  }
  return r;
}

int n, k;
ll res, numexx[100014];

int main ()
{
  R2(n, k);
  res = 0;
  FORDE(i, k, 1)
  {
    numexx[i] = powermod(k / i, n, MOD);
    for (int j = 2 * i; j <= k; j += i) 
    {
      numexx[i] -= numexx[j];
      numexx[i] += MOD;
      numexx[i] %= MOD;
    }
    res += i * numexx[i];
    res %= MOD;
  }
  printf("%lld\n", res);
  return 0;
}
