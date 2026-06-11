#include <iostream>

using namespace std;

int const NMAX = 50;
int v[1 + NMAX];

int main()
{
  int n, ans = 0;
  cin >> n;
  for(int i =1;i <= n;i++){
    cin >> v[i];
  }
  for(int i =1;i <= n;i++){
    for(int j = i+1;j <= n;j++){
      if(i != j){
        ans += v[i] * v[j];
      }
    }
  }
  cout << ans;
  return 0;
}
