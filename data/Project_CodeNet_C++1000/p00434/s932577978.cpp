#include <iostream>
using namespace std;

int main(){
  int k,s[31];

  for(int i=0;i<=30;i++) s[i]=0;

  for(int j=0;j<28;j++){
    cin>> k;
    s[k]=1;
  }

  for(int m=1;m<=30;m++){
    if(s[m]==0){
      cout <<m<<endl;
    }
  }
 
}