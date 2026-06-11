#include<bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	vector<int> v(n) ;
	
	rep(i,0,n){
		cin>>v[i] ;
	}

	ll count=0 ;

	rep(i,0,n){
		rep(j,i+1,n){
			rep(k,j+1,n){
				if(v[i]+v[j]>v[k] && v[i]+v[k]>v[j] && v[j]+v[k]>v[i]&& v[i]!=v[j] && v[j]!=v[k] && v[k]!=v[i]){
					count++ ;
					//cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n" ;
				}
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