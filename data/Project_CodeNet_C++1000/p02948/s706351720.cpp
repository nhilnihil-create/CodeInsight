#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n,m ;
	cin>>n>>m ;
	vector<vector<int>> jobs(m+1) ;

	rep(i,n){
		int a,b ;
		cin>>a>>b ;

		if(a>m)
			continue ;

		jobs[m-a].push_back(b) ;

	}

	priority_queue<int> q ;
	ll ans=0 ;

	for(int i=m-1;i>=0;i--){

		for(auto x:jobs[i]){
			q.push(x) ;
		}

		if(!q.empty()){

			int temp=q.top() ;
			ans+=temp ;
			q.pop() ;
		}
	}

	cout<<ans ;

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