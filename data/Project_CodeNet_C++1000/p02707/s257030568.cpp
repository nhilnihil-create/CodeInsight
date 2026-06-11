#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	map<int,int> m;
	rep(i,N-1)
	{
		int a;
		cin>>a;
		m[--a]++;
	}
	rep(i,N)
	{
		cout<<m[i]<<endl;
	}
	return 0;
}
