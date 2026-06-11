#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector <int> H(N);
  int cnt=0;
  int cntmax=0;
  cin>>H[0];
  for (int i=1;i<N;i++){
    
    cin>>H[i];
    
    if(H[i]<=H[i-1]){
      cnt++;
      cntmax=max(cntmax,cnt);
      continue;
    }
    cnt=0;
  }
  cout<<cntmax<<endl;
  return 0;
  
  }
