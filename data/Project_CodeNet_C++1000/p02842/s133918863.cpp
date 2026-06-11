#include<iostream>
using namespace std;
int main(){
int N;
  cin>>N;
  double tax=1.08;
  int i;
  for(i=1;i<=N;i++){
  	if((int)(i*tax)==N){
      cout<<i;  
	return 0;
 	}
  }
  cout<<":(";
}