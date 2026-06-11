#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<numeric>
#include<list>
#include<stack>
#include<sstream>
#define lli long long int
#define h 1000000007
#define s 2010
#define pf push_front
#define pb push_back
#define ub upper_bound
#define lb lowepr_bound
#define mp make_pair
#define pi 3.14159
using namespace std;
vector<lli>a(s,-1);
lli solve(lli sum)   
{
	lli i, cnt;
	if(sum==0)return 1;
	else if(sum>=3 && sum<=5) return 1;
	else if(a[sum]!=-1)return a[sum];
	else
	{
		cnt=0;
		for(i=3;i<=sum;i++) 
		{ if((sum-i)>=0)
	  	cnt=((cnt%h)+(solve(sum-i)%h))%h;
	  	else break;
	  } 
		a[sum]=cnt;
		return a[sum];
	} 
} 
int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL) ;
  lli i, n;
  cin>>n;
  cout<<solve(n)<<endl;
  return 0;
} 
