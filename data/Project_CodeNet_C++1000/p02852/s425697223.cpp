#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int n,m;
string s;

int next(int x)
{
	int y=x; 
	for(int i=1;i<=min(m,x);i++)
	{
		if(s[x-i]=='0')y=x-i;
	}
	return y;
}
int main(){
	cin>>n>>m;
	cin>>s;
	
	int ima=n;
	vector<int> v;
	v.push_back(ima);
	while(ima>0)
	{
		int po=next(ima);
		if(po==ima)
		{
			cout<<-1<<"\n";
			return 0;
		}
		else
		{
			v.push_back(ima);
			ima=po;
		} 
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size()-2;i++)
	{
		cout<<v[i+1]-v[i]<<" ";
		//cout<<v[i]<<" ";
	}
	cout<<"\n";
	return 0;
}