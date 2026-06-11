 #include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define fast std::ios_base::sync_with_stdio(false)
#define mod 1000000007
#define pi 3.14159265
int main() {
	fast;
	lli l,r,d,i,count=0;;
	cin>>l>>r>>d;
	for(i=l;i<=r;i++)
	{
		if(i%d==0)
			count++;
	}
	cout<<count;
	
	return 0;
}		