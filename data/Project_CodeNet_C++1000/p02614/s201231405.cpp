#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> mp;
int g[13][13];
int ct[13][2];
int get(int x,int y,int h,int w){
	int res = 0;
	vector<int> v;
	vector<int> v2;
	int tx = x,ty = y; 
	for(int i=0;i<h;i++){
		if(tx>>i & 1) v.push_back(i);
	}
	for(int i=0;i<w;i++){
		if(ty>>i & 1) v2.push_back(i);
	}
	int l1 = v.size();
	int l2 = v2.size();
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			if(g[v[i]][v2[j]]==2) res--;
		}
	}
	for(int i=0;i<l1;i++){
		res += ct[v[i]][0];
	}
	for(int i=0;i<l2;i++){
		res += ct[v2[i]][1];
	}
	return res;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int h,w,k;
	cin>>h>>w>>k;
	string s;
	int sum = 0;
	for(int i=0;i<h;i++){
		cin>>s;
		for(int j=0;j<w;j++){
			if(s[j]=='.') g[i][j] = 1;
			else g[i][j] = 2;
			if(g[i][j]==2) sum++;
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(g[i][j]==2) ct[i][0]++;
		}
	}
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			if(g[j][i]==2) ct[i][1]++;
		}
	}
	if(sum<k){
		cout<<0<<endl;
		return 0;
	}
	int ans = 0;
	for(int i=0;i<(1<<h);i++){
		for(int j=0;j<(1<<w);j++){
			if(sum - get(i,j,h,w)==k) ans++;
		}
	}
	cout<<ans<<endl;
	
}