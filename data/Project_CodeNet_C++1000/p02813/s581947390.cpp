#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw				"\n"


int main(void)
{
	CIN;
	ll tc,l,k,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	string s="",t="" ;
	cin>>n;
	tc=n;
	char c;
	while(tc--)cin>>c,s+=c;
	while(n--)cin>>c,t+=c;
	x=stoi(s),y=stoi(t);
	if(y<x){
		string tmp=t;
		t=s;
		s=tmp;
	}
	while(next_permutation(s.begin(),s.end()))
	{
		if(s==t)return cout<<cnt+1,0;
		cnt++;
	}
	cout<<0<<nw;

}
