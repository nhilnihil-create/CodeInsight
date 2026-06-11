#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define mod 1000000007
using namespace std;

int main(){
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	int n,id;
	scanf("%d",&n);
	vector<int> k(n),p(n),d(n);
	vector<vector<int>> c(n);
	rep(i,n){
		p[i]=-1;
	}
	rep(i,n){
		scanf("%d",&id);
		scanf("%d",&k[id]);
		c[id].resize(k[id]);
		rep(j,k[id]){
			scanf("%d",&c[id][j]);
			p[c[id][j]]=id;
		}
	}
	int p0;
	rep(i,n){
		if(p[i]==-1){
			p0=i;
		}
	}
	queue<int> q;
	rep(i,k[p0]){
		q.push(c[p0][i]);
	}
	d[p0]=0;
	int x;
	while(q.empty()==0){
		x=q.front();
		q.pop();
		d[x]=d[p[x]]+1;
		rep(i,k[x]){
			q.push(c[x][i]);
		}
	}

	rep(i,n){
		printf("node %d: parent = %d, depth = %d, ",i,p[i],d[i]);
		if(p[i]==-1)printf("root, [");
		else if(c[i].size()==0)printf("leaf, [");
		else printf("internal node, [");
		if(c[i].size()!=0){
			rep(j,k[i]-1){
				printf("%d, ",c[i][j]);
			}
			if(k[i]>0) printf("%d",c[i][k[i]-1]);
		}
		printf("]\n");
	}
}