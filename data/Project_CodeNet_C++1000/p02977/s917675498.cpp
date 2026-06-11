#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002

void check(vector<pair<int,int>> e,int n){
	/*
	vector<vector<int>> E(2*n,vector<int>());
	for(int i=0;i<e.size();i++){
		int a = e[i].first,b = e[i].second;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for(int j=0;j<n;j++){
		vector<int> dis(2*n,-1);
		dis[j] = j+1;
		queue<int> Q;
		Q.push(j);
		while(Q.size()!=0){
			int u = Q.front();
			Q.pop();
			for(int i=0;i<E[u].size();i++){
				int v = E[u][i];
				if(dis[v]!=-1)continue;
				int k = v+1;
				if(k>n)k-=n;
				dis[v] = (dis[u] ^ k);
				Q.push(v);
			}
		}
		cout<<dis[n+j]<<endl;
	}
	*/

}

int main(){
	
	int N;
	cin>>N;
	
	if(N==1){
		cout<<"No"<<endl;
		return 0;
	}
	vector<pair<int,int>> E;
	if(N%2==1){
		for(int i=2;i<=N;i+=2){
			E.emplace_back(1,i);
			E.emplace_back(i,i+1);
			E.emplace_back(1,N+i+1);
			E.emplace_back(N+i+1,N+i);
		}
		E.emplace_back(N+1,3);
	}
	else{
		int x;
		for(int i=0;true;i++){
			if((N>>i)&1){
				x=(1<<i);
				break;
			}
		}
		if(N==x){
			cout<<"No"<<endl;
			return 0;
		}
		for(int i=0;i+3<=N;i+=4){
			if(i!=0&&i!=x){
				E.emplace_back(x,i);
				E.emplace_back(i,i+1);
				E.emplace_back(i+1,i+2);
				E.emplace_back(i+2,i+3);
				E.emplace_back(i+3,i+N);
				E.emplace_back(i+N,i+N+1);
				E.emplace_back(i+1+N,i+2+N);
				E.emplace_back(i+2+N,i+3+N);
			}
			else if(i==0&&x!=2){
				E.emplace_back(x,i+1);
				E.emplace_back(i+1,i+2);
				E.emplace_back(i+2,i+3);
				E.emplace_back(i+3,i+N+1);
				E.emplace_back(i+N+1,i+N+2);
				E.emplace_back(i+N+2,i+N+3);
			}
			else{
				if(i==x){
					E.emplace_back(i,i+1);
					E.emplace_back(i+1,i+2);
					E.emplace_back(i+2,i+3);
					E.emplace_back(i+3,i+N);
					E.emplace_back(i+N,i+N+1);
					E.emplace_back(i+N+1,i+N+2);
					E.emplace_back(i+N+2,i+N+3);
				}
				else{
					E.emplace_back(2,1);
					E.emplace_back(2,3);
					E.emplace_back(3,N+1);
					E.emplace_back(N+1,N+2);
					E.emplace_back(N+2,N+3);
				}
			}
		
		}
		if(N%4==0){
			E.emplace_back(x,N);
			E.emplace_back(N-x,2*N);
		}
		else if(N%4==2){
			E.emplace_back(2,N);
			E.emplace_back(1,N-1);
			E.emplace_back(N-1,N-2);
			E.emplace_back(1,N+N-2);
			E.emplace_back(N+N-2,N+N-1);
			E.emplace_back(N-1,N+N);
		}
		
		
	}
	check(E,N);
	cout<<"Yes"<<endl;
	for(int i=0;i<E.size();i++)cout<<E[i].first<<' '<<E[i].second<<endl;
	
	return 0;
}