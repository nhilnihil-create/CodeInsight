#include <bits/stdc++.h>
using namespace std;
int h,w,m;
int a,b;
map<pair<int,int> ,bool> mp;
int x[300010],y[300010];
vector<int> v;
vector<int> t;
int mx=0,mx2=0;
int main(){
	cin>>h>>w>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		x[a]++;
		y[b]++;
		mp[make_pair(a,b)]=1;
		mx=max(mx,x[a]);
		mx2=max(mx2,y[b]);
	}
	for(int i=1;i<=h;i++){
		if(x[i]==mx){
			v.push_back(i);
		}
	}
	for(int i=1;i<=w;i++){
		if(y[i]==mx2){
			t.push_back(i);
		}
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<t.size();j++){
			if(!mp[make_pair(v[i],t[j])]){
				cout<<mx+mx2<<endl;
				return 0;
			}
		}
	}
	cout<<mx+mx2-1<<endl;
	return 0;
}