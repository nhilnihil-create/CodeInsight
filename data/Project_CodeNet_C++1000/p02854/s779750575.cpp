#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  std::cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for(int idx = 0; idx < n; idx++){
    std::cin >> a[idx];
    sum += a[idx];
  }

  long long sum2 = 0;
  long long min = INT_MAX;
  for(int idx = 0; idx < n; idx++){
    sum2 += a[idx];
    sum -= a[idx];
    if(abs(sum - sum2) < min){
      min = abs(sum - sum2);
    }
  }
  std::cout << min << '\n';
  return 0;
}
