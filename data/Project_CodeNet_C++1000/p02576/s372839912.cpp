#include <iostream>

using namespace std;

int main(){

	int n,x,t;
	cin>>n>>x>>t;
	int ans=n/x;
	if(n%x!=0){
	
		ans++;
	}
	cout<<t*ans<<'\n';
}
