#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,k;
	cin>>a>>b>>k;
	if(k<=a)
	 cout<<a-k<<" "<<b;
	else if(k<=a+b)
	 cout<<"0 "<<b-(k-a);
	else
	 cout<<"0 0";
	return 0;

}