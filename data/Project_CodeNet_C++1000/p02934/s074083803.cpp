#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  double rev = 0.0;
  rep(i, n){
    int a;
    cin >> a;
    rev += 1.0 / a;
  }
  cout << 1.0 / rev << endl;
  
  return 0;
}