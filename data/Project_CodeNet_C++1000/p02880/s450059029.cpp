#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  string ans="No";
  for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
      if(N==i*j)ans="Yes";
    }
  }
  cout<<ans<<endl;
}
    