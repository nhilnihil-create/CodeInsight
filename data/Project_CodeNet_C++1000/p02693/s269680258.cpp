#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>> n ;

	int a,b ;
	cin>>a>>b ;

	bool flag=false ;

	for(int i=a;i<=b;i++){
		if(i%n==0)
		{
			flag=true ;
			//cout<<i<<"\n" ;
			break ;
		}
	}

	if(flag==true)
		cout<<"OK";
	else
		cout<<"NG" ;
 

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