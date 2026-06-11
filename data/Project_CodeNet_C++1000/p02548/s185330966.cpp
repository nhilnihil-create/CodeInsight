#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
const ll mx=1e9+7;
#define pb push_back

#define all(n) n.begin(),n.end()

void solve()
{
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<n;i++)
	{
	cnt+=(n-1)/i ;
	}
	
	cout<<cnt;
	
}

int main()
{
	
solve();
		
	
	
}