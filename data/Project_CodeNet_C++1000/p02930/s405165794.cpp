#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
int n;
vector<int>v,vv;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<__builtin_ctz(i-j)+1<<' ';
		}
		cout<<endl;
	}
	return 0;
}