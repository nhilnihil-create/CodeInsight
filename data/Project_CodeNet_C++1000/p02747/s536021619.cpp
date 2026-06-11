#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  string X="";
  
  for(int i=0; i<5;i++){
    X=X+"hi";
    if(X==S){
      cout<<"Yes"<< endl;
      return 0;
    }
  }
  cout<<"No"<< endl;
}
