#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  double m, sum;
  for(;;){
    cin >> n;
    if (n == 0) { break; }
    sum = 0.0;
    m = 0.0;
    vector<int> v;
    for(int i = 0; i < n; i++){
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
      m += tmp;
    }
    m /= n;
    for(int i : v){
      sum += (i - m) * (i - m);
    }
    printf("%1.6f\n" , sqrt(sum / n));
  }
  return 0;
}