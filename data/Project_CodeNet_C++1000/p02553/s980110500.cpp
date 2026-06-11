#include <iostream>
using namespace std;

int main() {
	long int arr[4];
	for(int i=0; i<4; i++){
		cin>>arr[i];
	}
	long int ans = -1e18;
	for(int i=0; i<2; i++)ans=max(ans, max(arr[i]*arr[2], arr[i]*arr[3]));
	cout<<ans<<endl;
}