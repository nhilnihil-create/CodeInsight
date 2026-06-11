#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxx=10010;

vector<int> A[maxx],ans;
queue<int> task;
int f[maxx];
bool flag[maxx];
int v,e;

int main (){
	int x,y;
	bool xx=false;
	cin>>v>>e;
	for(int i=0;i<maxx;i++){
		f[i]=0;
		flag[i]=false;
	}
	while(e--){
		cin>>x>>y;
		A[x].push_back(y);
		f[y]++;
	}
	while(1){
		xx=false;
		for(int i=0;i<v;i++) {
			if(f[i]==0&&flag[i]==false) {
				xx=true;
				task.push(i);
			}
		}
		if(xx==false) break;
		while(task.empty()==0){
			x=task.front();
			flag[x]=true;
			ans.push_back(x);
			for(int k=0;k<A[x].size();k++){
				f[A[x][k]]--;
			}
			task.pop();
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
	
	
}
