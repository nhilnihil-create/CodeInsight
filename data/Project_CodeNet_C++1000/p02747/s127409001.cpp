#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  bool ans=true;
  
  
  for(int i=0;i<S.size();i++){
    if(i%2==0&&S.at(i)=='h'||i%2!=0&&S.at(i)=='i'&&S.size()%2==0){
    }
    else {
      ans=false;
    }
  }
  
  if(ans) cout << "Yes" << endl;
  
  else if(!ans) cout << "No" << endl;
}
