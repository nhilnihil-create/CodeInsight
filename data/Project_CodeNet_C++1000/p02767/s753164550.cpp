#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  rep(i, N) cin >> X.at(i);
  int mini=1000000;
  
  for(int i=1; i<=100; i++){
    int sum=0;
    
    for(auto e:X){
     sum += (e-i)*(e-i);
      
    }
    mini = min(mini, sum);
  }
  cout << mini << endl;
  return 0;
}


