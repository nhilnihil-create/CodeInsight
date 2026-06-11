#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

vector<pair<int,int> > adj[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		for(int j=0;j<m;j++){
			int x,y;
			cin>>x>>y;
			adj[i].push_back({x-1,y});
		}
	}
	
	
	int ans = 0;
	for(int i=0;i<(1<<n);i++){
		//cout<<i<<" : "<<endl;
		bool OK = true;
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				//cout<<j<<endl;
				cnt++;
				for(auto p:adj[j]){
					int y = p.first, st = p.second;
					//cout<<y<<" "<<st<<" "<<(i&(1<<y))<<endl;
					if( bool(i&(1<<(y))) != st ){
						OK = false;
						break;
					}
				}
			}
			if(!OK)break;
		}
		if(OK){
			ans = max(ans,cnt);
		}
	}
	cout<<ans;
	
	return 0;
}
