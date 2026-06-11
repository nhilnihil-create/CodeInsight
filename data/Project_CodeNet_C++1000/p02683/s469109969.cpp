#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
typedef long long ll;
const int N = 1e4 + 10, OO = 0x3f3f3f3f, mod = 1e9 + 7;

#define PI acos(-1)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)
#define range(vec)    \
  for (auto &x : vec) \
    cin >> x;
#define ALL(v) ((v).begin()), ((v).end())
#define SZ(v) ((int)((v).size()))
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

int n, m, x;

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  scanf("%d %d %d", &n, &m, &x);
  vector<int> cost(n);
  vector<int> a[n];
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &cost[i]);
    for (int j = 0; j < m; ++j)
    {
      int s;
      scanf("%d", &s);
      a[i].push_back(s);
    }
  }
  int ans = OO;
  for (int mskN = 0; mskN < (1 << n); ++mskN)
  {
    int costNow = 0;
    vector<int> algo(m);
    for (int i = 0; i < n; ++i)
    {
      if (mskN & (1 << i))
      {
        costNow += cost[i];
        for (int k = 0; k < m; ++k)
        {
          algo[k] += a[i][k];
        }
      }
    }
    bool ok = 1;
    for (int i = 0; i < m; ++i)
    {
      if (algo[i] < x)
      {
        ok = 0;
        break;
      }
    }
    if (ok)
      ans = min(ans, costNow);
  }
  if (ans == OO)
    ans = -1;
  printf("%d\n", ans);

  return 0;
}