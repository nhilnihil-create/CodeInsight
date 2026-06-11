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
	
	ll n;
	cin>>n;
	if(n>=400 && n<600)
		cout<<8;
	else if(n>=600 && n<800)
		cout<<7;
	else if(n>=800 && n<1000)
		cout<<6;
	else if(n>=1000 && n<1200)
		cout<<5;
	else if(n>=1200 && n<1400)
		cout<<4;
	else if(n>=1400 && n<1600)
		cout<<3;
	else if(n>=1600 && n<1800)
		cout<<2;
	else
		cout<<1;
	cout<<endl;

}

