#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	unordered_set<string> st ;

	for(int i=0;i<n;i++){
		string s ;
		cin>>s ;
		st.insert(s) ;

	}

	cout<<st.size() ;
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