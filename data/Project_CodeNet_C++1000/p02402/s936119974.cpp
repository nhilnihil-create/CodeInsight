#include <iostream>
using namespace std;
int main(){

  int n;
  long long a;
  long long min = 1000000;
  long long max = -1000000;
  long long sum = 0;

  cin >> n;
  
  for(int i=1;i<=n;i++) {
    cin >> a;
    if(a < min) min = a;
    if(max < a) max = a;
    sum += a;
  }

  cout << min <<" "<< max <<" "<< sum << "\n";
  
  return 0;
}