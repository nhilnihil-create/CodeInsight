#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	ll k;
	cin>>n>>k;
	int arr[n];
	vector<int> g[n];
	bool vis[n]={};
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	k--;
	int x = arr[0];
	bool cycle = false;
	int cnt=0;
	for(int i=0; i<k && !cycle; i++){
		if(!vis[x-1]){
			vis[x-1]=1;
			x = arr[x-1];
			cnt++;
		}
		else {
			cycle = true;
		}
	}
	k-=cnt;
	memset(vis, 0, sizeof(vis));
	int comp = 0;
	vector<int> path;
	while(!vis[x-1]){
		path.push_back(x);
		vis[x-1]=1;
		x = arr[x-1];
		comp++;
	}
	int m = k%comp;
	cout<<path[m]<<endl;
}
