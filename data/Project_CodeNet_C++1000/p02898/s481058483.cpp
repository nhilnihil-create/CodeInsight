#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=0; i<n; i++)
	{
		int num;
		cin>>num;
		if(num>=k)
		 cnt++;
	}
	cout<<cnt;
	return 0;
}