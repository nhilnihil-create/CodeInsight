#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){


	int n,q ;
	cin>>n>>q  ;

	unordered_map<int,int> mp ;

	rep(i,q){

		int x ;
		cin>>x ;

		rep(i,x){
			int c ;
			cin>>c ;
			mp[c]++ ;
		}

	}

	int count=0 ;

	for(int i=1;i<=n;i++){
		if(mp.find(i)==mp.end()){
			count++ ;
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