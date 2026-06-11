//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	cin>>s;
	for(int i=1;i<4;i++){
		if(s[i] == s[i-1]){
			cout<<"Bad";
			return 0;
		}
	}
	 cout<<"Good";
	
	return 0;
}
