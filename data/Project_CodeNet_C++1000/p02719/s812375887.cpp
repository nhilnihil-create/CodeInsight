#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	ll n,m;
	cin>>n>>m;
	cout<<min(n%m,m-(n%m))<<endl;
	return 0;
}