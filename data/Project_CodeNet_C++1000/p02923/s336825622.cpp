#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	vector<int> v(n) ;

	rep(i,n){
		cin>>v[i] ;
	}

	stack<int> st ;

	int answer=0 ;

	rep(i,n){

		if(i==0)
		{	st.push(v[i]) ;
		 	continue ;
		}

		if(v[i]<=st.top()){
			st.push(v[i]) ;
		}
		else{

			answer=max((int)st.size(),answer) ;

			while(!st.empty()){
				st.pop() ;
			}

			st.push(v[i]) ;

		}
	}

	answer=max((int)st.size(),answer) ;

	cout<<answer-1 ;

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