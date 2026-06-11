#include <iostream>
using namespace std;

int main() {
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x%2!=0&&i%2!=0) ans++;
		
	}
	cout<<ans;
	return 0;
}