#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define lli long long int
#define pb push_back
#define ph push
using namespace std;
void A_FIZZ_BUZZ()
{
	int x,y,n; cin>>x>>y>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%x==0 && i%y==0) cout<<"FizzBuzz\n";
		else if(i%x==0) cout<<"Fizz\n";
		else if(i%y==0) cout<<"Buzz\n";
		else cout<<i<<endl;
	}
}
void B_Internet_Provider()
{
	int x,n;cin>>x>>n;
	int t=x*n+x;
	int w=0;
	while(n--)
	{
		int d; cin>>d;
		w+=d;
	}
	cout<<t-w<<endl;
}
void C_TAX()
{
	int a,b,ans=-1; cin>>a>>b;
	for(int i=1;i<=1250;i++)
	{
		if((i*8)/100==a && (i*10)/100==b)
		{
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
}
int main(int argc, char *argv[])
{
	C_TAX();
}