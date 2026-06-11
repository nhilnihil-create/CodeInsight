#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  int ch = -1;
  while ((ch = getchar()) != EOF) {
    if (!isalpha(ch)) { putchar(ch); }
    else if (isupper(ch)) { putchar(tolower(ch)); }
    else { putchar(toupper(ch)); }
  }
  return 0;
}