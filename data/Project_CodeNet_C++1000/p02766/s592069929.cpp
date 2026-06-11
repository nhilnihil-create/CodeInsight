#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int N,K,ans=0,temp=0;
  cin >> N >> K;
  while(N>temp){
    temp += pow(K,ans)*(K-1);
    ans++; 
  }
  cout << ans << endl;
  
  return 0;
}
