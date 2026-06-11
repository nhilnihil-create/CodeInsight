#include<bits/stdc++.h>
#define endl '\n'
#define int long long
 
using namespace std;
 
int binarySearch(vector<int>& v,int s,int e,int sum){
	int l=s;
	int r=e;
	while(l+1<r){
		int m=(l+r)>>1;
		if(v[m]<sum){
			l=m;
		}
		else r=m;
	}
	return l;
}


int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n;
	cin>>n;
	map<int,int> mp;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		mp[x]++;
		if(mp[x]==1)v.push_back(x);
	}

	n=v.size();
	sort(v.begin(),v.end());

	// T if min_a+min_b > max_c
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int t=binarySearch(v,j,n,(v[i]+v[j]));
			if(t<n && v[i]+v[j]>v[t] && t > j){
				ans+=mp[v[i]]*mp[v[j]]*mp[v[t]];
				for(int k=j+1;k<t;k++){
					ans+=mp[v[i]]*mp[v[j]]*mp[v[k]];
				}
			}
		}
	}

	cout<<ans<<endl;


	return 0;
}
 