#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int a,b,c ;
	cin>>a>>b>>c ;
	set<int> st ;
	st.insert(a) ;
	st.insert(b) ;
	st.insert(c) ;
	
	if(st.size()==2)
		cout<<"Yes" ;
	else
		cout<<"No" ;

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