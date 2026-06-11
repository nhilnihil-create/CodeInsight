#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int ok=0;
while(n>0){
	if(n%10==7){
     ok=1;
     break;

	}
	n/=10;
	
}	
if(ok)
cout<<"Yes";
else cout<<"No";
}