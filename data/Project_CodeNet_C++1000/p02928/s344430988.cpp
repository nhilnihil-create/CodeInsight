#include <iostream>
#include <vector>
#include <utility>
using namespace std;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> vec;
  for(int i=0; i<n; i++){
    long long num;
    cin >> num;
    vec.push_back(num);
  }
  
  vector<pair<long long, long long>> info;
  for(int i=0; i<n; i++){
    long long smallerInA = 0;
    long long smallerInRemain = 0;
    for(int j=0; j<n; j++){
      if(i == j) continue;
      if(vec[i] > vec[j]) smallerInA++;
    }
    for(int j=i+1; j<n; j++){
      if(vec[i] > vec[j]) smallerInRemain++;
    }
    info.push_back(make_pair(smallerInA, smallerInRemain));
  }
  
  long long swapNum = 0;
  for(int i=0; i<n; i++){
   	long long a = info[i].first;
    long long b = info[i].second;
    long long tmp = a*(k-1);
    tmp %= 1000000007;
    tmp = b+tmp+b;
    tmp %= 1000000007;
    tmp = k * tmp;
    tmp %= 1000000007;
   	swapNum += tmp * modinv(2, 1000000007);
    swapNum %= 1000000007;
  }
  
  cout << swapNum << endl;
  return 0;
}
      