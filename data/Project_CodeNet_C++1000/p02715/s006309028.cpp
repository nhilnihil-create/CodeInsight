#include <bits/stdc++.h>
using namespace std;

int64_t power(int64_t a, int64_t b) {
  if(b==0)
    return 1;
  int64_t c=power(a,b/2)%1000000007LL;
  if(b%2==0)
    return c*c%1000000007LL;
  else
    return a*c%1000000007LL*c%1000000007LL;
}

int main() {
  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> x(K+1);
  int64_t s=0;
  for(int64_t i=K;i>=1;i--) {
    x.at(i)=(int64_t)power(K/i, N);
    for(int j=2;j<=K/i;j++)
      x.at(i) -= x.at(j*i);
    s += i*x.at(i);
  }
  cout << s%1000000007LL << endl;
}