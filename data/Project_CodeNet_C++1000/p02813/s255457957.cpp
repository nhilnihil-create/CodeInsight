#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){

	int n ;
	cin>>n ;

	vector<int> x(n) ; 
	vector<int> y(n) ;

	rep(i,n){
		cin>>x[i] ;
	}

	rep(i,n){
		cin>>y[i] ;
	}

	vector<int> temp=x ;

	sort(temp.begin(),temp.end()) ;

	int f1=0 ;
	int f2=0 ;
 	
 	int ans1=0 ;
 	int ans2=0 ;

 	do{
 		f1++ ;
 		f2++ ;
 		if(temp==x){
 			ans1=f1 ;
 		}

 		if(temp==y){
 			ans2=f2 ;
 		}
 	}while(next_permutation(temp.begin(),temp.end())) ;

 	cout<<abs(ans1-ans2) ;

}


int main(){


		int y ;

		y=1 ;
		//cin>>y ;

		while(y--){
 
			solve() ;

		}

}