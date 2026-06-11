#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  string S;
  cin >>S;
  char b=S[0];
  int ans=N;
  for(int i=1;i<N;i++){
    if(S[i]==b){
      ans--;
    }
    else{
      b=S[i];
    }
  }
  cout << ans <<endl;
}

    
        