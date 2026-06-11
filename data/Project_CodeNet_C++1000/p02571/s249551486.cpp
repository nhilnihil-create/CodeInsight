#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,T;
  cin>>S>>T;
  int a=S.size()-T.size(), b=T.size(), counter=0;
  for(int i=0;i<=a;i++){
    int counter2=0;
    for(int j=0;j<b;j++){
      if(S[j+i]==T[j])counter2++;
    }
    if(counter2>counter)counter=counter2;
  }
  int c=T.size()-counter;
  cout<<c<<endl;
  return 0;
}