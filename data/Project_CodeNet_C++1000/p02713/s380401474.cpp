#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a,sum=0;
	cin>>a;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=a;j++)
			for(int k=1;k<=a;k++)
				sum+=__gcd(__gcd(i,j),k);
	cout<<sum<<"\n";
	return 0;
}
