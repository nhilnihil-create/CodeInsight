#include <bits/stdc++.h>
using namespace std;

//type
#define ll long long
typedef pair<int, int> P;
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007    //10^9+7:合同式の法
#define MAXR 100000       //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first      //pairの一つ目の要素
#define S second     //pairの二つ目の要素
#define Z class
// OTHER
// xの二乗を返す (関数テンプレート版)
template <typename T>
T square(T x) { return x * x; }
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))
// loop
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= ll(b); i--)
#define FORA(i, I) for (const auto &i : I)

// vector
#define ALL(x) x.begin(), x.end()

// output
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n", (x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define ln cout << '\n'
template <Z A>
void pr(A a)
{
  cout << a;
  ln;
}
template <Z A, Z B>
void pr(A a, B b)
{
  cout << a << ' ';
  pr(b);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * *

int N, Q;
vector<int> edges[200000];
int64_t num[200000];

void dfs(int i, int p)
{
  for (int j : edges[i])
    if (j != p)
    {
      num[j] += num[i];
      dfs(j, i);
    }
}

int main()
{
  // input
  cin >> N >> Q;
  // edges 
  for (int i = 0; i < N - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    edges[a - 1].push_back(b - 1);
    edges[b - 1].push_back(a - 1);
  }
  // counter 
  for (int i = 0; i < Q; i++)
  {
    int p, x;
    cin >> p >> x;
    num[p - 1] += x;
  }

  dfs(0, -1);
  for (int i = 0; i < N; i++)
    cout << num[i] << " \n"[i == N - 1];
  return 0;
}
