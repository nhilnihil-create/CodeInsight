#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h,a;
	cin>>h>>a;
	int ans=ceil(h/float(a));
	cout<<ans;
	return 0;
	
}