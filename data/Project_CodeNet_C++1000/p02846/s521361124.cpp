#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main()
{
	ll t[2],a[2],b[3];
	cin>>t[0]>>t[1]>>a[0]>>a[1]>>b[0]>>b[1];
	a[0]*=t[0];
	b[0]*=t[0];
	a[1]*=t[1];
	b[1]*=t[1];

	if((a[0]+a[1])<(b[0]+b[1]))//a[0]-b[0]+a[1]-b[1]<0
	{
		swap(a[0],b[0]);
		swap(a[1],b[1]);
	}

	ll c[2];
	c[0]=a[0]-b[0];
	c[1]=a[1]-b[1];

	if(c[0]+c[1]==0)
	{
		cout<<"infinity"<<endl;
		return 0;
	}

	if(c[0]>0)
	{
		cout<<0<<endl;
		return 0;
	}

	ll ans=0;
	if(c[0]<0)ans--;

	ans+= c[1]/(c[1]+c[0])*2;
	
	if(c[1]%(c[1]+c[0])==0)ans--;


	cout<<ans<<endl;


	


	return 0;
}