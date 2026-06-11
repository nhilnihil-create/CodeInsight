#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int n=s.size();
	int flg=1;
	for(int i=0; i<n; i+=2){
		string a=s.substr(i,2);
		if(flg&&a=="hi") flg=1;
		else flg=0;
	}
	cout<<(flg?"Yes":"No")<<endl;
}