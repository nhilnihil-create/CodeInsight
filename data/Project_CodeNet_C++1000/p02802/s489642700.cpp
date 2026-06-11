#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ,m ;
	cin>>n>>m ;

	//pair--------------->penalty,mark if ac

	vector<int> AC(n) ;
	vector<int> pen(n) ;

	for(int i=0;i<m;i++){

		int p ;
		string s ;

		cin>>p>>s ;
		p-- ;

		if(AC[p]==1){
			continue ;
		}
		else{

			if(s=="WA"){
				pen[p]++ ;
			}
			else
			{
				AC[p]=1; 
			}

		}

	}

	int ac=0 ;
	int penalty=0 ;

	for(int i=0;i<n;i++){
		
		ac+=AC[i] ;
		
		if(AC[i])
		penalty+=pen[i] ; 
	}

	cout<<ac<<" "<<penalty ;
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