#include <iostream>
#include <queue>
#define INF 200000
using namespace std;
typedef pair<int,int> P;
P a;
priority_queue< P,vector<P> ,greater<P> > pq;
int map[101][101];
bool decided[101];
int sum,n;
int node,count;
void check(){
	node=1;
	decided[node]=true;
	count=n-1;
	while(1){
		for(int i=1;i<=n;i++){
			if(map[node][i]!=-1&&!decided[i]){
				a=make_pair(map[node][i],i);
				pq.push(a);
			}
		}
		while(decided[pq.top().second])pq.pop();
		sum+=pq.top().first;
		node=pq.top().second;
		decided[node]=true;
		count--;
		if(count==0)break;
		pq.pop();
	}
}

int main(){
	cin >>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> map[i][j];
		}
	}
	sum=0;
	check();
	cout << sum<<endl;
}