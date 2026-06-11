#include <bits/stdc++.h>
using namespace std; 
   
int main(){
  string S,T,U;
  cin >> S >> T;
  int A=S.size(),B=T.size(),mincount=1000;
  for(int i=0;i<A-B+1;i++){
    int count=0;
    U=S.substr(i,B);
    for(int j=0;j<B;j++){
      if(T.at(j)!=U.at(j)){
        count++;
      }
    }
    mincount=min(mincount,count);
  }
  cout << mincount << endl;
}
  
  