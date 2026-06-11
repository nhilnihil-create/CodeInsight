#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  float tax=1.08;
  //float ex=n/tax;//税抜き価格
  //int cost=ex;
  for(int i=1;i<=50000;i++){
    int sum=i*tax;
  	if(sum==n){
    	cout<<i<<endl;
      	return 0;
    }
  }
  cout<<":("<<endl;
}