#include <iostream>

using namespace std;

int main(){

	long long int n,m;
	long long int ans;
	cin>>n>>m;
	if(n==1||m==1){
	
		cout<<1;
		return 0;
	}
	ans=n*m;
	cout<<(ans+1)/2;
	return 0;
}
