#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);   
	ll n,a[200009],m,k,ans=0,fl=0;
	string s;
	cin>>n>>m;
	float tem=ceil((float)n/0.08);
	ll temp=ll(tem);
	while((ll)floor(temp*0.08)==n)
	{
		if((ll)floor(temp*0.1)==m)
		{
			break;
		}
		temp++;
	}
	if((ll)floor(temp*0.08)==n)
		cout<<temp<<endl;
	else
		cout<<"-1\n";
	return 0;
}