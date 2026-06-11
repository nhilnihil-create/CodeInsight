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
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
LL calc(LL x,LL y)
{
	if(x>=y)return x*(x+1)/2+y*(y-1)/2;
	else return x*(x-1)/2+y*(y+1)/2;
}
int main(){
	string s;cin>>s;
	
	LL a=0,b=0;
	LL ans=0;
	char ima='>';
	for(int i=0;i<s.length();i++)
	{
		if(ima=='<')
		{
			if(s[i]=='<')a++;
			else ima='>',b++;
		}	
		else
		{
			if(s[i]=='>')b++;
			else
			{
				ima='<';
				ans+=calc(a,b);
				a=1,b=0;
			}
		}
	
	}
	ans+=calc(a,b);
	cout<<ans<<"\n";
	return 0;
}