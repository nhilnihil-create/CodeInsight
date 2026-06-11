#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 1000000;
typedef pair<int,int> P;
int main(){
	int N,M,S,T,u,v;
	vector<int> vec[300000];
	int ans[300000];
	priority_queue<P,vector<P>,greater<P>> que;
	P p;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>u>>v;u--;v--;
		vec[u].push_back(v+N);
		vec[u+N].push_back(v+2*N);
		vec[u+2*N].push_back(v);
	}
	fill(ans,ans+3*N,MAX);
	cin>>S>>T;S--;T--;
	ans[S]=0;
	que.push(P(0,S));
	while(!que.empty()){
		p = que.top();
		que.pop();
		for(int i:vec[p.second]){
			if(ans[i]>ans[p.second]+1){
				ans[i]=ans[p.second]+1;
				que.push(P(ans[i],i));
			}
		}
	}
	
	if(ans[T]<MAX)cout<<ans[T]/3;
	else cout<<-1;
	return 0;
}