#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	long long int x,k,d;
	cin>>x>>k>>d;
	if(x<0)x=-x;
	long long int a = x/d,b = x%d;
	if(k>a){
		if((a-k)%2==0){
			cout<<b<<endl;
		}else{
			cout<<d-b<<endl;
		}
	}else{
		cout<<x-k*d<<endl;
	}

	return 0;
}