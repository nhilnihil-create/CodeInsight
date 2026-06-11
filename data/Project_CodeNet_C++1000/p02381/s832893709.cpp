#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  int n;
  vector<int> s;
  double ans;
  double ave;
  int temp;

  while(true){
    cin >> n;
    if( n == 0){
      break;
    }
    s.resize(n);
    for( auto &i :s){
      i = 0;
    }
    for( int i = 0; i < n; ++i){
      cin >> temp;
      s[i] = temp;
    }
    
    ave = 0;
    for( auto i : s){
      ave += i; 
    }
    ave /= n;

    ans = 0;
    for( auto i : s){
      ans += (i-ave)*(i-ave);
    }
    ans /= n;

    cout << fixed << setprecision(5) << sqrt(ans) << endl;
  }
  return 0;
}