#include<iostream>
#define ll long long
using namespace std;
int a[200000+5];
int main(){
	ll n,max1,sum=0;
  	cin>>n;
  	for(int i=1;i<=n;i++){
      	cin>>a[i];
    }
  	max1=a[1];
  	for(int i=2;i<=n;i++){
    	if(a[i]<max1)
          	sum+=max1-a[i];
      	else
          	max1=a[i];
    }
  	cout<<sum<<endl;
  	return 0;
}