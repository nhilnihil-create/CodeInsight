#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fs first
#define se second
#define M 1000000007
#define pii pair<long long,long long>
 
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
unordered_map<char,pii>dir;
ll D=1e9;
 
bool check(ll x,ll y,ll n,ll m){
	return (x>=0 && y>=0 && n>x && m>y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	ll a,b,c;
	cin>>a>>b>>c;
	ll k;
	cin>>k;

	int i=0;
	for( i=0;i<=k;i++)
	{
		if((1<<i)*b>a)
			break;
	}
	b*=(1<<i);
	k-=i;
	c*=(1<<k);
	if(a<b && b<c)
		cout<<"Yes";
	else
		cout<<"No";
	cout<<endl;

}

