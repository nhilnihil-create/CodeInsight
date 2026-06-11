#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll N=(1e9+5)*1e9;
ll n,a,b,c,d,t,mx=-N; 
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b>>c>>d;
	mx=max(mx,a*c);
	mx=max(mx,a*d);
	mx=max(mx,b*c);
	mx=max(mx,b*d);
	cout<<mx<<endl;
}