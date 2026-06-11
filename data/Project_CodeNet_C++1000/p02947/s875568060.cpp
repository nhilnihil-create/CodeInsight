#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int n ;
	cin>>n ;

	unordered_map<string,int> mp ;

	rep(i,n){
		string s ;
		cin>>s ;

		sort(s.begin(),s.end()) ;

		mp[s]++ ;

	}

	ll sum=0 ;

	for(auto x: mp){

		sum+=((ll)x.second*((ll)x.second-1))/2 ;

	}

	cout<<sum ;

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