#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  
  int check=0;
  
  for(int i=0;i<(S.size()-1)/2+1;i++){
    if(S[i]==S[(S.size()-1)/2+1+i]){
      check++;
    }
  }
  if(check==(S.size()-1)/2){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}