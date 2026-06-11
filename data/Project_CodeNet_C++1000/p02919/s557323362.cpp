#include <cstdio>
#include <set>

int main()
{
  int n;
  scanf("%d", &n);
  int p[100000];
  int idx[100000];
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", p + i);
    p[i]--;
    idx[p[i]] = i;
  }
  std::set<int> set;
  long long ans = 0;
  for (int x = n - 1; x >= 0; --x)
  {
    int i = idx[x];
    set.insert(i);
    long long pos[] = {-1, -1, n, n};
    {
      auto it = set.find(i);      
      for (int j = 1; j >= 0; --j)
      {
        if (it == set.begin()) break;
        --it;
        pos[j] = *it;
      }
    }
    {
      auto it = set.find(i);
      for (int j = 2; j < 4; ++j)
      {
        ++it;
        if (it == set.end()) break;
        pos[j] = *it;
      }
    }
    long long c = (i - pos[1]) * (pos[3] - pos[2]) + (pos[2] - i) * (pos[1] - pos[0]);
    ans += (x + 1) * c;
  }
  printf("%lld\n", ans);
  return 0;
}
