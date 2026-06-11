         /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
const int mod=1e9+7;         
const int N=2e5+4;

int main()
{
	int n,k,c;

	scn(n); scn(k); scn(c);

	string s;

	cin>>s;

	//I mean day if I write time anywhere...

	//earliest[i] tells the earliest time we can start the ith day's work
	//latest[i] tells the latest time we can start the ith day's work
	int earliest[k+1],latest[k+1];

	int cnt=1;

	//times can be greedily be alloted. Consider the case of earliest, If I can
	//work at this instant, then why not, if I skip today's work then we can
	//see that the earliest time of all later works including today's work
	//will only get delayed.

	for(int i=0;i<n;i++)
	{
		if(s[i]=='o')
		{
			earliest[cnt++]=i+1;

			i+=c;

			if(cnt>k)
			break;
		}
	}

	cnt=k;

	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='o')
		{
			latest[cnt--]=i+1;

			i-=c;

			if(cnt<=0)
			break;
		}
	}

	//rep(i,1,k+1)
	//cout<<earliest[i]<<" "<<latest[i]<<endl;

	vector<int> ans;

	rep(i,1,k+1)
	if(latest[i]==earliest[i])
	ans.pb(latest[i]);

	for(int it:ans)
	priln(it);

    return 0;
}