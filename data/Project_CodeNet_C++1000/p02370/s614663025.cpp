#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;

typedef long long ll;
struct P{
	int pos,time;
};
bool operator<(P a,P b){return a.time<b.time;}
int a[100000],n,m,u1,u2;
P b[100000];
vector<int>e[100000];
int main() {
	cin>>m>>n;
	for(int i=0;i<m;i++){
		b[i]=P{i,-1};
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>u1>>u2;
		e[u1].push_back(u2);
		a[u2]++;
	}
	queue<int>p;
	for(int i=0;i<m;i++){
		if(a[i]==0){
			p.push(i);
			b[i].time=0;
		}
	}
	while(!p.empty()){
		int t=p.front();p.pop();
		for(int i=0;i<e[t].size();i++){
			if(b[e[t][i]].time<b[t].time+1){
				b[e[t][i]].time=b[t].time+1;
				p.push(e[t][i]);
			}
		}
	}
	sort(b,b+m);
	for(int i=0;i<m;i++){
		cout<<b[i].pos<<endl;
	}
	//cout<<2<<endl;
}