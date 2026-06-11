#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<sz(s);i++){
		if(i&1){
			if(s[i]=='R'){
				cout<<"No";
				return 0;
			}
		}
		else{
			if(s[i]=='L'){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
}