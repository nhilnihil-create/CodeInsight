#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;

int main()
{
  int n; cin >> n;
  bool flag = false;
  if (n%2)
  {
    flag = true;
  }
  
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (flag)
  {
    long long a_mean = a[n/2];
    long long b_mean = b[n/2];
    cout <<(long long) (b_mean - a_mean + 1) << endl;
  }
  else
  {
    long double a_mean = (a[n/2]+a[n/2-1])/2.0;
    long double b_mean = (b[n/2]+b[n/2-1])/2.0;
    cout <<(long long ) (2 * (b_mean - a_mean) + 1) << endl;
  }
  
  
  
  
}