#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){	

	int n,m ;
	cin>>n>>m ;

	vector<int> h(n)  ;
	
	rep(i,n){
		cin>>h[i] ;
	}

	vector<priority_queue<int>> adj(n) ;

	rep(i,m){

		int a,b ;
		cin>>a>>b ;

		a-- ;
		b-- ;

		adj[a].push(h[b]) ;
		adj[b].push(h[a]) ;

	}

	int count=0; 

	rep(i,n){

		if(adj[i].empty()){
			count++ ;
		}
		else{

			int temp=adj[i].top() ;
			if(temp<h[i]){
				count++ ;
			}
		}

	}

	cout<<count ;

}

int main(){

	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}