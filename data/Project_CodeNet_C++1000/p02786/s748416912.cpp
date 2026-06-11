#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vec             vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define inf             1e18
#define no_of_test(x)        int x; cin>>x; while(x--)
const int mod = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	no_of_test(x)
	{
       int n;
       cin>>n;
       int cnt=0;
       int r=1;
       while(n>=1)
       {
           n=n/2;
           cnt+=r;
           r=r*2;
       }
       cout<<cnt<<'\n';
	}
	return 0;
}