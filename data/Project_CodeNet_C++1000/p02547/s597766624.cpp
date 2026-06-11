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
int cnt=0,yes=0;
while(n--)
{
	int x,y;
	cin>>x>>y;
	if(x==y)cnt++;
	else
cnt=0;
	
	if(cnt==3)yes=1;
}

(yes)? cout<<"Yes":cout<<"No";
	
}

int main()
{
	
solve();
		
	
	
}