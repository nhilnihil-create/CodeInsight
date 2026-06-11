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
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef pair<int,int> P;

const int MOD=1000000007;

int n;

void ans(vector<char> &v,int count)
{
	if(v.size()==n)
	{
		for(int i=0;i<v.size();i++)cout<<v[i];
		cout<<"\n";
	}
	else
	{
		for(int i=1;i<=count+1;i++)
		{
			char moji=(char)('a'+i-1);
			v.push_back(moji);
			if(i==count+1)ans(v,count+1);
			else ans(v,count);
			v.pop_back();
		}
	}
}
int main()
{
	cin>>n;
	vector<char> po;
	ans(po,0);
	return 0;
}