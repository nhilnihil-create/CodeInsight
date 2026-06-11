#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
#define mod 1000000007
map<int,int> mp;
set<int> s; 
int arr[N];
signed main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mp[arr[i]]++;s.insert(arr[i]);
	}
	if(s.size()>3) cout<<"No";
	else{
		int f=1;map<int,int> vis;
		if(s.size()==3){
			for(int i=1;i<=n;i++){
				if(!vis[arr[i]]){
					if(mp[arr[i]]!=n/3){
						f=0;
						break;
					}
				}
				vis[arr[i]]=1;
			}
			set<int> ::iterator it;int sum=0;
			for(it=s.begin();it!=s.end();it++){
				sum=sum^*it;
			}
			if(sum) f=0;
		}else if(s.size()==2){
			if(mp[0]!=n/3) f=0;
			for(int i=1;i<=n;i++){
				if(!vis[arr[i]]&&arr[i]){
					if(mp[arr[i]]!=2*n/3){
						f=0;
						break;
					}
				}
				vis[arr[i]]=1;
			}	
		}else if(s.size()==1){
			if(mp[0]!=n) f=0;
		}
		if(f) cout<<"Yes";else cout<<"No";
	}
	return 0;
}

/*

2
BWWB

4
BWBBWWWB

5
WWWWWWWWWW

BWBW
*/