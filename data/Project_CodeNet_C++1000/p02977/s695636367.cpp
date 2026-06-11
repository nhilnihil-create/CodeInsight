#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007ll
#define ROD 1000000009ll
#define INF 1e18
#define MIN(a,b) (a>b?b:a)
using namespace std;
#define mp make_pair
#define pb push_back
#define  piii pair<pair<ll,ll>,ll>
#define pii pair<ll,ll>
#define fi first
#define se second
#define MAXN 1000055

int main()
{
	ll n;
	scanf("%lld",&n);
	//cout<<(1&3)<<" ";
	if(__builtin_popcount(n)==1||n<3)
	{
		printf("No\n");
	}
	else if((n&3)==3)
	{
		printf("Yes\n");
		cout<<"1 2\n"<<"2 3\n"<<"3 "<<n+1<<"\n"<<n+1<<" "<<n+2<<"\n"<<n+2<<" "<<n+3<<"\n";
		ll pos=3;
		while(n!=pos)
		{
			cout<<n+pos<<" "<<pos+1<<"\n";
			cout<<pos+1<<" "<<pos+2<<"\n";

			cout<<pos+2<<" "<<pos+3<<"\n";
			cout<<pos+3<<" "<<pos+4<<"\n";
			cout<<pos+4<<" "<<n+pos+1<<"\n";
			cout<<n+pos+1<<" "<<n+pos+2<<"\n";
			cout<<n+pos+2<<" "<<n+pos+3<<"\n";
			cout<<n+pos+3<<" "<<n+pos+4<<"\n";
			pos+=4;
		}
	}
	else if((n&3)==0)
	{
		printf("Yes\n");
		cout<<"1 2\n"<<"2 3\n"<<"3 "<<n+1<<"\n"<<n+1<<" "<<n+2<<"\n"<<n+2<<" "<<n+3<<"\n";
		ll pos=3;
		while(n-1!=pos)
		{
			cout<<n+pos<<" "<<pos+1<<"\n";
			cout<<pos+1<<" "<<pos+2<<"\n";

			cout<<pos+2<<" "<<pos+3<<"\n";
			cout<<pos+3<<" "<<pos+4<<"\n";
			cout<<pos+4<<" "<<n+pos+1<<"\n";
			cout<<n+pos+1<<" "<<n+pos+2<<"\n";
			cout<<n+pos+2<<" "<<n+pos+3<<"\n";
			cout<<n+pos+3<<" "<<n+pos+4<<"\n";
			pos+=4;
		}

		ll low=(n&-n);
		ll high=n^(n&-n);
		low=n+low+1;
		cout<<n<<" "<<low<<"\n";
		cout<<high<<" "<<2*n<<"\n";
		
	}
	else if((n&3)==1)
	{
		printf("Yes\n");
		cout<<"1 2\n"<<"2 3\n"<<"3 "<<n+1<<"\n"<<n+1<<" "<<n+2<<"\n"<<n+2<<" "<<n+3<<"\n";
		ll pos=3;
		while(n-2!=pos)
		{
			cout<<n+pos<<" "<<pos+1<<"\n";
			cout<<pos+1<<" "<<pos+2<<"\n";

			cout<<pos+2<<" "<<pos+3<<"\n";
			cout<<pos+3<<" "<<pos+4<<"\n";
			cout<<pos+4<<" "<<n+pos+1<<"\n";
			cout<<n+pos+1<<" "<<n+pos+2<<"\n";
			cout<<n+pos+2<<" "<<n+pos+3<<"\n";
			cout<<n+pos+3<<" "<<n+pos+4<<"\n";
			pos+=4;
		}
		cout<<n-1<<" "<<n<<"\n";
		cout<<n<<" "<<1<<"\n";
		cout<<1<<" "<<n+n-1<<"\n";
		cout<<n+n-1<<" "<<n+n<<"\n";
	}
	else if((n&3)==2)
	{
		printf("Yes\n");
		cout<<"1 2\n"<<"2 3\n"<<"3 "<<n+1<<"\n"<<n+1<<" "<<n+2<<"\n"<<n+2<<" "<<n+3<<"\n";
		ll pos=3;
		while(n-3!=pos)
		{
			cout<<n+pos<<" "<<pos+1<<"\n";
			cout<<pos+1<<" "<<pos+2<<"\n";

			cout<<pos+2<<" "<<pos+3<<"\n";
			cout<<pos+3<<" "<<pos+4<<"\n";
			cout<<pos+4<<" "<<n+pos+1<<"\n";
			cout<<n+pos+1<<" "<<n+pos+2<<"\n";
			cout<<n+pos+2<<" "<<n+pos+3<<"\n";
			cout<<n+pos+3<<" "<<n+pos+4<<"\n";
			pos+=4;
		}
		
		cout<<n-1-1<<" "<<n-1<<"\n";
		cout<<n-1<<" "<<1<<"\n";
		cout<<1<<" "<<n+n-1-1<<"\n";
		cout<<n+n-1-1<<" "<<n+n-1<<"\n";
		
		cout<<n<<" "<<n-1<<"\n";
		cout<<2<<" "<<2*n<<"\n";
	}
}
