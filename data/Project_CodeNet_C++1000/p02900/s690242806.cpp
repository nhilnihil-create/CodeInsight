#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
typedef long long ll;
#define int long long
vector<int>v,v1;
bool is_prime(ll x)
{
	int shang=sqrt(x);
	for(int i=2;i<=shang;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
signed main()
{
	ll x,b;cin>>x>>b;
    for(int i=2;i<=sqrt(x);i++)
    {
        while(x%i==0)
        {
            x/=i;
            v.push_back(i);
        }
    }
    if(x>1)v.push_back(x);
    for(int i=0;i<v.size();i++)
    {
    	if(is_prime(v[i])&&b%v[i]==0)
    	{
    		v1.push_back(v[i]);
		}
	}
	sort(all(v1));
	int m=unique(all(v1))-v1.begin();
	cout<<m+1;
}