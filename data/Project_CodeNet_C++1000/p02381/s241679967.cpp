#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  while(1)
  {
    int n;
    cin >> n;
    if(n == 0) break;

    vector<int> s(n);
    for(int i = 0; i < n; i++)
      cin >> s[i];

    double m = 0;
    for(int i = 0; i < n; i++)
      m += s[i];
    m /= n;

    double a2 = 0;
    for(int i = 0; i < n; i++)
      a2 += (s[i] - m)*(s[i] - m) / n;

    cout << fixed << setprecision(10) << sqrt(a2) << endl;
  }
  return 0;
}