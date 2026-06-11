#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main()
{
	cin>>n>>k;
	n%=k;
	cout<<min(k-n,n)<<endl;
	return 0;
}