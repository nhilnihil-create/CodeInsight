#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  int sum = 0;
  rep(i, n-1)rep2(j, i+1, n){
    sum += d[i] * d[j];
  }
  cout << sum << endl;
  
  return 0;
}