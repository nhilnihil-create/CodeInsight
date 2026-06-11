#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<cmath>
#include<map> 
#include<string>
#include<queue>
#include<stack> 
#include<bitset>
#include<list>
#include<set>
#include<utility>
#include<iomanip>
#define IO ios::sync_with_stdio(false)
#define eps 1e-7
#define int long long
using namespace std;
const int N=200000+5;
int sum,a[N],n;
signed main()
{
	IO;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum^=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cout<<(sum^a[i])<<endl;
	}
}