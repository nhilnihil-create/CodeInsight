#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int K;
  string S;
  cin >> K >> S;
  
  int l;
  if(S.size() > K)  l = K;
  else  l = S.size();
  
  rep(i, l){
   cout << S.at(i); 
  }
  if(S.size() > K) cout << "...";
  cout << endl;
  return 0;
}