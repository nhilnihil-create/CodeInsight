//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s,t;
	cin>>s>>t;
	int n,m;
	cin>>n>>m;
	string h;
	cin>>h;
	
	if(h == s){
		cout<<n-1<<" "<<m;
	}else{
		cout<<n<<" "<<m-1;
	}
	
	return 0;
}
