#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mod=(int)1e9+7;

int main()
{
	ios;
	int x,ans;
	for(int i=0;i<5;i++)
	{
		cin>>x; 
		if(x!=i+1) ans=i+1;
	}
	cout<<ans;
	return 0;
}
