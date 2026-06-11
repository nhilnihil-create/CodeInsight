#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
 
#define int long long
#define INF 1001001001
int ans[2200];
int dis[2200][2200];
vector<int> v[2200];
 
void bfs(int start){
 
 	queue<int> q;
 	
 	q.push(start);
 	
 	dis[start][start] = 1;
 	
 	while(!q.empty()){
 	
 		int u = q.front();
	 	q.pop();
	 	for( int v : v[u]){
		  
		    if(dis[v][start] == 0){
	 		
	 			dis[v][start] = dis[u][start]+1;		
	 			q.push(v);
		    }
     	}
 		
	}
 
	
}
 
 
int32_t main() {
	
    int N,X,Y;
  
    cin >> N >> X >> Y;
	
	X--;Y--;
	
	
	for(int i=0; i<N-1;i++){
		
		v[i].push_back(i+1);
		v[i+1].push_back(i);
		
	}
	
	v[X].push_back(Y);
	v[Y].push_back(X);
 
 	for(int i=0; i<N; i++)
 		bfs(i);
 		
 	for(int i=0; i<N; i++){
 		for(int j=i+1; j<N; j++){
 			
 			 ans[dis[j][i] -1]++;
		 }
 		
	 }	
 	
 	for(int i=1; i<N; i++){
 		
 		cout << ans[i] << endl;
	 }
 	
 	
}