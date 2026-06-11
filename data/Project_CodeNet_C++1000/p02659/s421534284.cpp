#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A;
  string B;
  cin>>A>>B;
  long long temp=0;
  for(int i=0;i<4;i++){
     if(B.at(i) !='.'){
      temp+=B.at(i)-'0';
      temp*=10;
    }
  }
  temp/=10;
  long long ans=A*temp/100;
  cout<<ans<<endl;
    
  return 0;
  }