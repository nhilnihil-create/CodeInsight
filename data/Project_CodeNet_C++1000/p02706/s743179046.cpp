#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m, d;
  int total = 0;
  std::vector<int> days;
  cin >> n >> m;
  for(int i=0; i < m; i++){
      cin >> d;
      total += d;
  }
  if(total > n) cout << -1;
  else cout << n - total;
}