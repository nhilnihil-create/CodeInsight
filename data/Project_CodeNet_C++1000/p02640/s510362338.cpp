//Practice more and more
//learn for better
#define bn begin()
#define en end()
#define mx 5000010
#define pb push_back
#define PI (2.0*acos(0.0))
#define ALL(a) a.begin(),a.end()
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rep(a,b) for(int a=0;a<b;++a)
#define fastio ios::sync_with_stdio(false)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int>  vi;
typedef vector<ll>   vll;
bool m[200010];
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
	int a,b,n,i,t,tmp;
	cin>>a>>b;
	if(b>=a*2&&b<=a*4&&b%2==0)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;

	return 0;
}