#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
  long n, k;
  cin >> n >> k;

  vector<long> h;
  for(int i = 0; i< n; i++){
    long tmp;
    cin >> tmp;
    h.push_back(tmp);
  }
  sort(h.begin(), h.end());

  size_t ret;
  if(n <= k){
   ret = 0;
  }else {
   ret = accumulate(h.begin(), h.end() -k, 0LL);
  }
  cout << ret << endl;
  return 0;
}
