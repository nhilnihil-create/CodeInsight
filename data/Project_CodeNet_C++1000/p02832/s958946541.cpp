#include <iostream>
#include <vector>
#include <string>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int leave = 0;
  rep(i, n){
    int a;
    cin >> a;
    if (a == leave+1) leave++;
  }
  if (leave == 0) cout << -1 << endl;
  else cout << n - leave << endl;
  
  return 0;
}