#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int num=n/500;
	int rem=n%500;
	int ans=1000*num;
	int rem2=rem/5;
	ans+=rem2*5;
	cout<<ans;
	return 0;
}