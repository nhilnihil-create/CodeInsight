#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int x[n],y[n];
  rep(i,n) cin >> x[i] >> y[i];
  
  int town[n];
  rep(i,n) town[i] = i+1;
  
  ld ans = 0.0;
  int count = 0;
  do{
    ld dist = 0.0;
    for(int i = 0; i < n-1; i++)
    {
      dist += hypotl(x[town[i]-1] - x[town[i+1]-1], y[town[i]-1] - y[town[i+1]-1]);
    }       
    count++;
    ans += dist;
  }while(next_permutation(town,town+n));
  
  cout << fixed;
  cout << setprecision(20);
  cout << (long double)(ans/count) << endl;
}