#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

int n;


int main(){
  while(cin>>n, n!=0){

    int counter=n;

    for(int k=1;k<=n;k++){
      for(int i=2;i<=sqrt(n+k);i++){
	if(((n+k)%i)==0){
	  counter--;
	  break;
      }
      }
    }

    cout<<counter<<endl;

  }

  return 0;
}