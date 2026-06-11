#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	int h,w,m;cin>>h>>w>>m;
	multiset<int>se;
	map<int,int>cnt;
	map<int,vector<int>>mp;
	rep(i,m){
		int x,y;scanf("%d%d",&x,&y);
		mp[x].push_back(y);
		cnt[y]++;
	}
	for(auto p:cnt){
		se.insert(p.second);
	}
	int Max=0;
	for(auto&p:mp){
		for(int&y:p.second){
			se.erase(se.find(cnt[y]));
			cnt[y]--;
			se.insert(cnt[y]);
		}
		Max=max(Max,(int)p.second.size()+*se.rbegin());
		for(int&y:p.second){
			se.erase(se.find(cnt[y]));
			cnt[y]++;
			se.insert(cnt[y]);
		}
	}
	cout<<Max<<endl;
}