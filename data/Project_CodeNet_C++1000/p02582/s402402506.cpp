#include<iostream>
using namespace std;
int main(){
  int ans=0;
  char S[3];
  cin >> S;
  for(int i=0;i<3;i++){
  if(S[i]=='R'){
  ans++;
    }
  }
  if(S[0]=='R' && S[1]=='S' && S[2]=='R'){
    ans=1;
  }
  cout << ans << endl;
}