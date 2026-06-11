#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include<map>
using namespace std;
#define debug freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI acos(-1)
typedef long long ll;
const int maxn=2e6+10;


map<ll,int> mp;
int main()
{
	ios;
	ll x;
	int N;
	bool bl=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>x;
		if(bl==1)
			continue;
		mp[x]++;
		if(mp[x]>=2)
			bl=1;
	}
	if(bl==1) cout<<"NO";
	else cout<<"YES";
	return 0;
}