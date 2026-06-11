#include <bits/stdc++.h>
#include <cstdlib>
#include <string>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  int N,min=0,ans=0;
  cin >> N;
  vector<int> P(N);
  rep(i,N) {
    cin >> P[i];
    if(i==0) {min=P[i]; ans=1;}
    else if(min>=P[i]) {
      ans++;
      min=P[i];
    }
  }
  
  cout << ans << endl;
  return 0; 
}