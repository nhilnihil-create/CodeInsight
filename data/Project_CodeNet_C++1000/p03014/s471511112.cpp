#include<iostream>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<set>
#include<queue>
#include<cmath>

using namespace std;
#define LL long long

int H,W,ans=0;
char S[2222][2222];
vector<int>hor[2222],var[2222];

int main() {
	cin>>H>>W;
	for(int i=1;i<=H;i++){
		hor[i].push_back(0);
		hor[i].push_back(W+1);
	}
	for(int i=1;i<=W;i++){
		var[i].push_back(0);
		var[i].push_back(H+1);
	}
	for(int i=1;i<=H;i++)for(int j=1;j<=W;j++){
		cin>>S[i][j];
		if(S[i][j]=='#'){
			hor[i].push_back(j);
			var[j].push_back(i);
		}
	}
	for(int i=1;i<=H;i++)sort(hor[i].begin(),hor[i].end());
	for(int i=1;i<=W;i++)sort(var[i].begin(),var[i].end());
	for(int i=1;i<=H;i++)for(int j=1;j<=W;j++){
		if(S[i][j]=='#')continue;
		auto hi=lower_bound(hor[i].begin(),hor[i].end(),j);
		auto vi=lower_bound(var[j].begin(),var[j].end(),i);
		ans=max(ans,*hi-*(hi-1)+*vi-*(vi-1)-3);
	}
	cout<<ans<<endl;
	return 0;
}

