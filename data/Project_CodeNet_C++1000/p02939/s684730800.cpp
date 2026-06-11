#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll z=0;

int main() {
  string S;
  cin >> S;
  int K=S.size();
  vector<int> DP(K+1,0);
  DP[0]=0;
  DP[1]=1;
  if(S[0]!=S[1])
  DP[2]=2;
  else if(S[0]==S[1])
  DP[2]=1;
  for(int i=3;i<=K;i++){
    if(S[i-2]!=S[i-1]){
      DP[i]=DP[i-1]+1;
    }
    else
      DP[i]=DP[i-3]+2;
  }
  
  cout << DP[K] << endl;
  
}
