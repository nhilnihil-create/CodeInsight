#include <iostream>

using namespace std;


int main(){

	int a,b;
	cin>>a>>b;
	int ans=0;
	int sum=1;
	while(sum<b){
	
		sum+=a-1;
		ans++;
	}
	cout<<ans<<"\n";
		return 0;
}
