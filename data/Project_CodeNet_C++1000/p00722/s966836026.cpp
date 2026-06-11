#include<iostream>

using namespace std;

bool isPrime(int n){
  for(int i=2;(long)i*i<=n;i++){
    if(n%i==0)return false;
  }
  return n!=1;
}

int main(){
    
  int a,d,i,n,j,y;
  
  while(cin>>a>>d>>n,a||d||n){
    i=j=0;
      while(i<n){
          y=a+j*d;
         
          if( isPrime(y)){
	    i++;
	  }
	  j++;
      }
      cout<<y<<endl;
  }

  return 0;
}