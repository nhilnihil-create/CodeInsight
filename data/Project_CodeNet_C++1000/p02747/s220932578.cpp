#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	bool x = 0;
	cin>>s;
	string hitachi = "";
	
	for(int i = 0; i < s.size(); i+=2){
		
		hitachi += "hi";
		
		if(s == hitachi)
			x = 1;
	}
	
	if( x == 1)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}