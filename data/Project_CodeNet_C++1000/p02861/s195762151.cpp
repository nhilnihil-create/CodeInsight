#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

double res(int n)
{
  int ans = 1;
  rep(i, n) ans *= (n - i);
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<P> v(n);
  long double sum = 0;
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  do{
    rep(i, n - 1) {
      sum += sqrt(pow((v[i].first - v[i + 1].first), 2) + (pow((v[i].second - v[i + 1].second), 2)));
    }
  }while(next_permutation(v.begin(), v.end()));
  
  cout << setprecision(20) << sum / res(n) << endl;
     
  
  return 0;
}
