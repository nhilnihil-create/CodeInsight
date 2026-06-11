#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
  {
    int n;
    cin >> n;
    vector<double> vec(n + 1);
    cout << fixed << setprecision(6);
    for (int i = 1; i <= n; i++)
    {
      cin >> vec[i];
    }
    double ans = 0;
    for (int i = 1; i < n; i++)
    {

      sort(vec.begin(), vec.end());
      ans = (vec[i] + vec[i + 1]) / 2;
      vec[i + 1] = ans;
    }
    cout << vec[n] << endl;
  }