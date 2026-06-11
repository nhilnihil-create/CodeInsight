#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

void solve(){
	
	string s1 ;
	string s2 ;

	cin>>s1>>s2 ;

	//cout<<s1<<" "<<s2 ;
	int count=0 ;

	for(int i=0;i<s1.length();i++){
		if(s1[i]!=s2[i])
			count++ ;
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