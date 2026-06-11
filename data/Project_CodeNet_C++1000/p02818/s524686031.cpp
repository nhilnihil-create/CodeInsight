#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N];
int main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	long long a,b,k;
	cin>>a>>b>>k;
	if(a>=k)cout<<a-k<<" "<<b;
	else if(b>=k-a)
	{

		cout<<"0 "<<b-(k-a);
	}
	else cout<<"0 0";

}
