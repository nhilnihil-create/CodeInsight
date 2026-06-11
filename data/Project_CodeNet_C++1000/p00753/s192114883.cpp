#include<iostream>
using namespace std;

int main(){
  int i,j,n,num[300000];
  
  for(i = 1; i < 300000; i++){
    num[i]=0;
  }

  for(i = 2; i < 300000; i++){
    if(num[i]==0){
      for(j = 2*i; j < 300000; j+=i){
	num[j]=1;
      }
    }
  }

  while(1){
    int count=0;
    cin >> n;
    if(n==0)break;
    for(i = n+1; i <=n*2; i++){
      if(num[i]==0)count++;
    }
    
    if(n==1){
      cout << 1 << endl;
    }else{
      cout << count << endl;
    }
  }
  return 0;
}