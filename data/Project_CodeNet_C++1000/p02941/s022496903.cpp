	#include <bits/stdc++.h>
	using namespace std;
	#define bolt ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
	#define test int tt; cin>>tt; while(tt--)
	#define ll long long
	#define vi vector<int>
	#define pb push_back
	#define F first
	#define S second
	#define mod 1000000007
	#define all(v) v.begin(), v.end()
	#define allr(v) v.rbegin(), v.rend()
	#define deb(x,y) cout<< #x << "=" <<x <<","<<#y<<"="<<endl; 
	const int N = 2e5+5;
	const ll MAX = 1e9 +7;
	 
	int main()
	{
		//test{
		int n;
		cin>>n;
		
		ll a[n],b[n];
		for(int i=0;i<n; i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n; i++)
		{
			cin>>b[i];
		}
		priority_queue< pair<ll,ll> >pq;
		
		for(int i=0;i<n; i++)
		{
			if(b[i]>=a[i])
			pq.push({b[i],i});
			else if(b[i]<a[i])
			return cout<<"-1",0;
		}
		
		int ind;
		ll val,ans=0,z=0;
		int pre = -1;
		while(!pq.empty())
		{
			 auto it = pq.top();
			  pq.pop();
			 
			 val = it.F;
			 ind = it.S;
			 
			 if(pre == ind)
			 {
				 cout<<"-1\n";
				 return 0;
			}
			pre = ind;
		 
			 z = (val-a[ind])/(b[(ind-1+n)%n]+b[(ind+1)%n]);
			 ans += z;
			 b[ind] -= (b[(ind-1+n)%n]+b[(ind+1)%n]) * z;

			 if(b[ind] < a[ind])
			 {
				 cout<<"-1\n";
				 return 0;
			}
			 
			 if(b[ind]>a[ind])
			 pq.push({b[ind],ind});
		}
		cout<<ans<<"\n";
	//}
		return 0;		
	}
			
