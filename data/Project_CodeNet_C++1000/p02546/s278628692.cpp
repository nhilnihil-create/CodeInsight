#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


void solve(){
	
	string s; cin>>s;
	
	if(s[s.size()-1]=='s'){
		s=s+"es";
	}
	else{
		s=s+'s';
	}
	
	cout<<s<<"\n";
	
	return;
}




int main() {
	
	
	

   int t=1; //cin>>t;
   
   while(t--){
   	solve();
   }
    
    
    return 0;
}