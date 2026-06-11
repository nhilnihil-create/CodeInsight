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
	for(int i=0;i<v;i++) {
		if(f[i]==0&&flag[i]==false) {
			task.push(i);
			flag[i]=true;
		}
	}
	while(1){
		xx=false;
		while(task.empty()==0){
			x=task.front();
			ans.push_back(x);
			for(int k=0;k<A[x].size();k++){
				f[A[x][k]]--;
				if(f[A[x][k]]==0&&flag[A[x][k]]==false) {
					task.push(A[x][k]);
					flag[A[x][k]]=true;
					xx=true;
				}
			}
			task.pop();
		}
		if(xx==false) break;
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
	
	
}
