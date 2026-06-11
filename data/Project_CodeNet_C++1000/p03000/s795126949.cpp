#include <iostream>

using namespace std;

int const NMAX = 50;
int v[1 + NMAX];

int main()
{
  int n, m, sum = 0, ans = 1;
  cin >> n >> m;
  for(int i =1;i <= n;i++){
    cin >> v[i];
    sum += v[i];

    if(m >= sum){
      ans++;
    }
  }
  cout << ans;
  return 0;
}
