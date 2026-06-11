#include <iostream>
using namespace std;

int a[101];
int n, k;

int main(){
  cin >> n >> k;
  for(int i = 0; i < k; i++){
    int di, aij; cin >> di;
    for(int j = 0; j < di; j++){
      cin >> aij;
      a[aij]++;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans += (!a[i] ? 1 : 0);
  }
  cout << ans << endl;
}