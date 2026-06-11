#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){	

	int n ;
	cin>>n ;

	string s ;
	cin>>s ;

	stack<char> st ;

	for(int i=0;i<n;i++){


		if(st.empty())
			st.push(s[i]) ;
		else{
			char temp=st.top() ;
			if(s[i]==temp){
				continue ;
			}
			else{
				st.push(s[i]) ;
			}
		}
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