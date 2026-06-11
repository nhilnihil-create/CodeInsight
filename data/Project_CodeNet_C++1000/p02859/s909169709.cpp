#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <iterator>
#include <functional>
#include <limits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include<chrono>
#include<string>

using namespace std;

#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define ins insert

/*int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>v;
		ll val=-1;
		while(n--)
		{
			ll temp;
			cin>>temp;
			v.pb(temp);
		}

		ll mini=10000000;

		if(v.size()==1)
		{
			cout<<val<<endl;
			continue;
		}

		else{
		for(ll i=0;i<v.size();i++)
		{
			set<ll>s;
			ll cnt=0;
			ll j;
			for(j=i;j<v.size();j++)
			{
				auto temp=s.find(v[j]);
				if(temp==s.end())
				{
					s.insert(v[j]);
					cnt++;
				}

				else
				{
					cnt++;
					break;
				}
			}
			//cout<<cnt<<endl;

			if(cnt>1)
			mini=min(mini,cnt);

			i=j-1;
		}

			cout<<mini<<endl;
		}

	}
}*/




int main() {
	

	ios_base::sync_with_stdio(false);
	cin.tie();
	ll r;
	cin>>r;
	ll val=r*r;
	cout<<val;
	

}
