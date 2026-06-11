#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int solve(int n,int m){
	int flag[21][21]={};
	int field[21][21]={};
	queue<pair<int,int> >q;
	for(int i=0;i<m;i++){
		string s;
		cin >> s;
		for(int j=0;j<n;j++){
			if(s[j]=='.')field[i][j]=0;
			if(s[j]=='#')field[i][j]=-1;
			if(s[j]=='@'){
				field[i][j]=1;
				flag[i][j]=1;
				q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		int a = p.first;
		int b = p.second;
		if(a>0){
			if(flag[a-1][b]==0&&field[a-1][b]==0){
				q.push(make_pair(a-1,b));
				flag[a-1][b]=1;
			}
		}
		if(a<m-1){
			if(flag[a+1][b]==0&&field[a+1][b]==0){
				q.push(make_pair(a+1,b));
				flag[a+1][b]=1;
			}
		}
		if(b>0){
			if(flag[a][b-1]==0&&field[a][b-1]==0){
				q.push(make_pair(a,b-1));
				flag[a][b-1]=1;
			}
		}
		if(b<n-1){
			if(flag[a][b+1]==0&&field[a][b+1]==0){
				q.push(make_pair(a,b+1));
				flag[a][b+1]=1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(flag[i][j]==1)ans+=1;
		}
	}
	return ans;
}


int main(){
	int n,m;
	while(1){
		cin >> n >> m;
		if(n==0&&m==0)break;
		cout << solve(n,m) <<endl;
	}
	return 0;
}