#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
using namespace std;

int d[100];
int f[100];
int map[100][100];
int dis;
int n;
queue<int> q;
void visit(int);
void searchQ(int);

int main(){
	dis=0;
	int i,j,k,u,v;
	for(i=0;i<100;i++) d[i]=-1; //?????¢??¨?????¢??\
	cin >> n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			map[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		cin>>u>>k;
		for(j=0;j<k;j++){
			cin>>v;
			map[u-1][v-1]=1; //?????????????????????????????????????????????
		}
	}
	visit(0);
	for(i=0;i<n;i++) cout<< i+1 <<" "<<d[i]<<endl;
	return 0;
}

void visit(int a){
	q.push(a);
	d[a]=0;

	while(!q.empty()){
		int i=q.front();
		q.pop();
		searchQ(i);
		
	}
}

void searchQ(int a){//?????\????????¶?????????
	for(int i=0;i<n;i++){
		if(map[a][i]==1 && d[i]==-1){
			q.push(i);
			d[i]=d[a]+1;
		}
	}
}