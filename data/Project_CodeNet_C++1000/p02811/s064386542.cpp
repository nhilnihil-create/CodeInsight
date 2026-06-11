#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const long long int  mod  = 1000000007;
int main()
{
	ll n,m;
	cin>>n>>m;
	float f=(float)m/n;
	if(f>500)
		cout<<"No";
	else
		cout<<"Yes";
}
