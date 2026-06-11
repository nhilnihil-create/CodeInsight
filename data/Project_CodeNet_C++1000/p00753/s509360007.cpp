#include<iostream>
using namespace std;

int main(){

  bool pn[246913]={};
  for(int i=2;i<=123456;i++){
    for(int j=2;i*j<=246912;j++){
      pn[i*j]=true;
    }
  }

  int n;
  while(cin>>n, n){
    int cnt=0;
    for(int i=n+1;i<=2*n;i++){
      if(pn[i]==false) cnt++;
    }

    cout<<cnt<<endl;
  }
  
  return 0;
}