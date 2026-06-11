#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K, count=0;
  
  cin >> N >> K;
  
  for(;N>0;){
    N/=K;
    count +=1;
  }
  
  cout << count;
}
      