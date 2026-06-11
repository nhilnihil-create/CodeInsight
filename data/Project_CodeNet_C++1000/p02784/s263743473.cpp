#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,N;
  cin>>H>>N;
  
  while(N-->0)
  {
    int attack;
    cin>>attack;
    H-=attack;
    if(H<1) {
      cout<<"Yes \n";
      return 0;
    }
  }
  cout<<"No \n";
  return 0;
}