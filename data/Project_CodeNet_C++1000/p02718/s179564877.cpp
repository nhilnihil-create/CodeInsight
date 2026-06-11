#include <iostream>
using namespace std;
int main(){
 	int cnt=0,n,m,sum=0;
  	cin>>n>>m;
  	int a[n];
  	for(int i=0;i<n;i++){
     	cin>>a[i];
      	sum+=a[i];
    }
  	for(int i=0;i<n;i++){
     	if(a[i]*4*m>=sum){
         	cnt++; 
        }
    }
  	if(cnt>=m){
    	cout<<"Yes";  
    }
  	else cout<<"No";
}