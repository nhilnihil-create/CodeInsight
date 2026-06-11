#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	long double h,n;
	cin>>h>>n;
	cout<<ceil(h/n)<<endl;
	return 0;
}