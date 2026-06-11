#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
 string s;
  cin>>N>>s;
  for(int i=0;i<(int)s.size();i++){
    char c=s.at(i);
    if(c+N<=90){
    cout<<(char)(c+N);
  }else{
      cout<<(char)(c+N-26);
    }
}
}