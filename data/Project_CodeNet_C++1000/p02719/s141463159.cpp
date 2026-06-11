#include <iostream>

using namespace std;
typedef long long ll;

int main(){
	
	ll n,k;
	cin>>n>>k;
	ll temp=n/k;
	temp=n-temp*k;
	if(temp<k-temp){
	
		cout<<temp<<'\n';
		return 0;
	}
	cout<<k-temp<<'\n';
	return 0;
}
