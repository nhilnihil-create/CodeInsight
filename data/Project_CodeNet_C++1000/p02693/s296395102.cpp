#include<bits/stdc++.h>

#define ASORT(arr, n)          sort(arr,arr+n)
#define SORT(v)             sort(v.begin(), v.end())
#define REV(v)              reverse(v.begin(), v.end())
#define FOR(i, n)           for (int i=0; i<n; i++)
#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI                  acos(-1.0)

using namespace std;

typedef long long              ll;
typedef unsigned long long     ull;
typedef vector<int>            vi;

const double eps = 1e-9;


int main()
{
  fastIO();
	ll k , a, b ;
	cin>>k>>a>>b;
	for(int i=a; i<=b; i++)
	{
		if(i%k==0)
		{
			cout<<"OK"<<'\n';
		//	break;
		return 0;
		}
	
	}
			cout<<"NG"<<'\n';
	


 return 0;
 }
