#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
	int n,t ;
	cin>>n>>t ;

	if(t==1)
	{
		cout<<0 ;
		return ;
	}

	int sock=0 ;
	int step=0 ;

	while(true){

		sock+=n ;
		step++ ;

		if(sock>=t){
			cout<<step ;
			return ;
		}

		sock-=1 ;

	}
	

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