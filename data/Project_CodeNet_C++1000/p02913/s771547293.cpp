#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000000000
#define mod 1000000007
#define ld long double
#define point complex<double>
#define pi  acos(-1)
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
long double dot (point a,point b)
{
	return (conj(a)*b).real();
}
long double theta(point a,point b)
{
	long double x=dot(a,b);
	x/=abs(a);
	x/=abs(b);
	return acos(x)*180/pi;
}
long double cross(point a,point b)
{
	return (conj(a)*b).imag();
}
long double arg2(point a)
{
	return arg(a)*180/pi;
}
int n;
string s;
bool find(int cnt)
{
//	cout<<cnt<<endl;
	unordered_map<string,vector<int>>mapi;
	string ss;
	for(int i=0;i<n;i++)
	{
		if(i<cnt)
		{
			ss.push_back(s[i]);
			if(i==cnt-1)
			{
				mapi[ss].push_back((i+1)-cnt);
			}
		}
		else
		{
			ss.erase(ss.begin());
			ss.push_back(s[i]);
			mapi[ss].push_back((i+1)-cnt);
		}
	}
	bool res=0;

	for(auto m:mapi)
	{
		if((m.second[m.second.size()-1]-m.second[0])>=cnt)return 1;
	}
	return 0;
}
int main()
{
    IO

	cin>>n>>s;
	int S=1,E=n/2.0,M;
	ll res=0;
	while(S<=E)
	{
		M=(S+E)/2.0;
		if(find(M))
		{
			S=M+1;
			res=M;
		}
		else E=M-1;
	}
	cout<<res<<endl;
    return 0;
}
