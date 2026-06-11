#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	int n; cin>>n;
	string s; cin>>s;
	for(char &c:s){
		int x=c-'A';
		x+=n;
		x%=26;
		cout<<(char)('A'+x);
	}
}
