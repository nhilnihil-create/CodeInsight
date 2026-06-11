#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	int ans=b/a;
	if(b%a)
	ans++;
	cout<<ans<<endl;
}
