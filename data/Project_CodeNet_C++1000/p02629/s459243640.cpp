#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using ll = long long;
using namespace std;        
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define ar array


void solve(){
		ll n;cin>>n;n--;
	   	if(n==0){
			cout<<'a'<<endl;
			return;
		}	
		vector<char> name;
		while(n>0){
		  name.pb('a'+n%26);
		  n/=26;
		  n--;
		  if(n==0){
			  name.pb('a');
			  break;
		  }		  
		}
		reverse(name.begin(),name.end());
		for(auto x: name){
			cout<<x;
		}
		cout<<endl;		
		

}

int main(){
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
//	freopen("input.txt",r,"stdin");
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}



