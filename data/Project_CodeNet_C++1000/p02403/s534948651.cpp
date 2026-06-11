#include<iostream>
using namespace std;
int main(){
  int h[100],w[100];
  int i=0;
  while(1){
    cin>>h[i]>>w[i];
    if(h[i]==0&&w[i]==0){
      break;
    }
    i++;
  }
  for(int j=0;j<i;j++){
    for(int k=0;k<h[j];k++){
      for(int l=0;l<w[j];l++){
	cout<<'#';
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return(0);
}