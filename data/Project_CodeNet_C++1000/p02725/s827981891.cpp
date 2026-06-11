#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  int maxi=0;
  cin >> A.at(0);
  for(int i=1; i<N; i++){
    cin >> A.at(i);
    maxi = max(A.at(i) - A.at(i-1), maxi);
  }
  if(A.at(0) == 0){
   maxi = max(maxi, K-A.at(N-1)); 
  }else{
   maxi = max(maxi, K-A.at(N-1)+A.at(0)); 
  }
  cout << K -  maxi << endl;
  return 0;
}


