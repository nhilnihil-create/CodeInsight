#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>

int main()
{
	float a,b,c;
	cin>>a>>b>>c;
	int ans = c * ceil(a/b);
	cout<<ans<<endl;
}