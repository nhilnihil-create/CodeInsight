#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define oo 100000
 
using namespace std;
 
int32_t main ()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}	
	map<int,int> mp;
	vector<bool> visited(n);
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++){
		if(visited[i])continue;
		
		if(i && v[i]==v[i-1]){
			visited[i]=1;
			visited[i-1]=1;
		}
		
		else if(!i && n>1 && v[i]==v[i+1]){
			visited[i]=1;
			visited[i+1]=1;
		}
		
		if(mp.find(v[i])!=mp.end()){
			visited[i]=1;
			continue;
		}
		mp[v[i]]++;

		for(int j=2;j*v[i]<1000000+1;j++){
			mp[v[i]*j]++;
		}

	}

	int ans=0;
	for(int i=0;i<n;i++){
		if(!visited[i])ans++;
	//	else cout<<v[i]<<endl;
	}

	cout<<ans<<endl;

	return 0;
}
