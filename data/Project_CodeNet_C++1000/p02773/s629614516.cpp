#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define mp make_pair
#define pb push_back
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)  ((a)*((b)/gcd(a,b)))
#define pi 3.14159265358979323846
#define reus ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int32_t main()
{
	reus;

//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
    
    int n;
    cin>>n;
    map<string,int>mp;
    set<string>sts;
    string s;
    for(int i=0;i<n;i++)
    {
    	cin>>s;
    	mp[s]++;
	}
	int maxi=INT_MIN;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
    	maxi=max(maxi,i->second);
	}
	for(auto i=mp.begin();i!=mp.end();i++)
	{
		if(i->second==maxi)
		{
			sts.insert(i->first);
		}
	}
	for(auto it=sts.begin();it!=sts.end();it++)
	{
		cout<<*it<<endl;
	}

	return 0;
}