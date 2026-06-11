#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,k,count=0;
	cin>>n>>k;
	n=n%k;
	while(n>k/2) {
		n=abs(n-k);
		count++;
	}
	cout<<n<<endl;
	return 0;
}