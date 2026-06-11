#include <iostream>
#include <cmath>

using namespace std;
int main(){
  long  n;
  cin >> n;

  long min_dist = n;
  for(long i = 1L; i <= sqrt(n); i++) {
    if(n%i == 0) {
      min_dist = min(min_dist, i+(n/i)-2L);
    }
  }
  cout << min_dist << endl;
  return 0;
} 
