#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long llong;

#define MAX 200001
const llong mod = 1000000000 + 7;

int main()
{
  char S[MAX];
  int Q;
  int t, f;
  char c;
  int isReversed = 0;
  scanf("%s", S);

  vector<char> v(S, S + strlen(S));

  scanf("%d", &Q);

  for (int i = 0; i < Q; i++)
  {
    scanf("%d", &t);
    if (t == 2)
    {
      scanf("%d %c", &f, &c);
      if ((f == 1 && !isReversed) || (f == 2 && isReversed))
      {
        v.insert(v.begin(), c);
      }
      else
      {
        v.push_back(c);
      }
    }
    else
    {
      isReversed = isReversed ? 0 : 1;
    }
  }

  if (isReversed)
    reverse(v.begin(), v.end());

  for (auto ch : v)
  {
    printf("%c", ch);
  }

  return 0;
}