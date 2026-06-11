#include<iostream>
using namespace std;
int main(){
  string S;
  string T;
  int count =0;
  int max=0;
  cin >> S >> T;
  int a=S.size()-T.size();
  int b=T.size();
  for(int i=0; i<a+1;i++){
    for(int j=0; j<b; j++){
      if(S.at(i+j)==T.at(j)){
        count++;
      }
    }
    if(max< count){
      max=count;
    }
    count=0;
  }
  cout<< T.size()-max<< endl;
}