#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  string S;
  cin>>N>>S;
  for(char i:S){
    char a=(char)(int)i+N;
    if(a>'Z')
      a=a-('Z'-'A'+1);
    cout<<a;
  }
  cout<<endl;
}