#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	long long int ans=0;
	for(int i=1;i<=n;i++){
		ans=ans+(n-1)/i;
	}
	cout<<ans;
	return 0;
}			