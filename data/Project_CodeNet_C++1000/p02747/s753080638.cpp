#include<bits/stdc++.h>

using namespace std;

int main(){
  string S;
  cin >> S;
  
  for(int i=0;i<S.size();i++){
    if(S.size()%2!=0){
      cout << "No" << endl;
      break;
    }
    if(i%2==0 && S.at(i)=='h'){
      continue;
    }else if(i%2==1 && S.at(i)=='i'){
      if(i==S.size()-1)
      cout << "Yes" << endl;
      continue;
    }else{
      cout << "No" << endl;
      break;
    }
    
  }
}
