#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){	
	
	int n ;
	cin>>n ;

	vector<int> v(n) ;

	rep(i,n){
		cin>>v[i] ;
	}	

	unordered_map<int,int> mp ;

	rep(i,n){
		if(mp[v[i]]==1){
			cout<<"NO" ;
			return ;
		}
		mp[v[i]]=1 ;

	}

	cout<<"YES" ;
}


int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;0

	while(y--)
	{	
		solve() ;
	}

}