#include<iostream>
using namespace std;

int main(){
  string S;
  cin >> S;
  int i, count;
  i=0;
  count=1;
  bool flag=true;
  while(i<S.size()-1){
    if(S[i]==S[i+1] && flag){
      if(i==S.size()-2){
        i=i+2;
      }else{
      	i=i+2;
      	count=count+1;
      }
      flag=false;
    }else{
      i=i+1;
      count=count+1;
      flag=true;
    }
    //cout << "i count " << i << " " << count << endl;
  }
  
  cout << count << endl;
  
  return 0;
}