#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		if(i%3&&i%5)
			sum+=i;
	cout<<sum<<"\n";
	return 0;
}
