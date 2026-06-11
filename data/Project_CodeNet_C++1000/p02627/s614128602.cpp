#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int main()
{
    char c;
    cin >> c;

      if ('a'<=c && 'z'>=c)  c='a';
  else if ('A'<=c && 'Z'>=c) c='A';
    cout << c << endl;
    return 0;
}