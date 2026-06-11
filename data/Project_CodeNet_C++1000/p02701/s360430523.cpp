#include <stdio.h>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX 200001
const llong mod = 1000000000 + 7;

int main()
{
  int N, flag = 1, ans = 0;
  char S[11];
  vector<string> v;

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%s", &S);
    v.push_back(S);
  }

  sort(v.begin(), v.end());

  string a = "";
  for (auto str : v)
  {
    if (str.compare(a))
      ans++;
    a = str;
  }

  printf("%d\n", ans);

  return 0;
}