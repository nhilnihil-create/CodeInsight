#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n,k;
	cin>>n>>k;
	n=n*500;
	if(n>=k)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}