#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <typename T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <typename T> void chmin(T &x,T y){x=x<y?x:y;return;} 
typedef long long ll;
typedef unsigned long long ull;

ll a,b,x;

int main()
{
	cin>>x;
	for(ll i=-200;i<=200;i++)
		for(ll j=-200;j<=200;j++)
			if(i*i*i*i*i-j*j*j*j*j==x)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
	return 0;
}