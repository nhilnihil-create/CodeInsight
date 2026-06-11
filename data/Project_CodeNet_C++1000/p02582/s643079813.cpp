#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	
	bool a = s[0] == 'R';
	bool b = s[1] == 'R';
	bool c = s[2] == 'R';
	
	if(a && b && c){
		cout<<3<<endl;
	}
	else if((a && b ) || (b && c)){
		cout<<2<<endl;
	}
	else if(a || b || c)
		{
			cout<<1<<endl;
		}
	else{
			cout<<0<<endl;
		}
	
	
	}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	
	
	}	
	
