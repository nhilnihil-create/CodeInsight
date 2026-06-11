#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	vector<int> v(n) ;

	for(int i=0;i<n;i++){
		cin>>v[i] ;
	}

	for(int i=0;i<n;i++){
		if(v[i]%2==0){
			if(v[i]%3!=0 && v[i]%5!=0)
			{
				cout<<"DENIED" ;
				return ;
			}
		}
	}

	cout<<"APPROVED" ;

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