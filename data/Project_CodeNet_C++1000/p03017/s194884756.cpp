#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
	a--; b--; c--; d--;
	string s; cin>>s;
	for(int i=a; i<c; i++){
		if(s.at(i)=='#'&&s.at(i+1)=='#') {
			cout << "No" << endl;
			return 0;
		}
	}
	for(int i=b; i<d; i++){
		if(s.at(i)=='#'&&s.at(i+1)=='#') {
			cout << "No" << endl;
			return 0;
		}
	}
	if(d<c){
		bool flg{};
		for(int i=b-1; i<d; i++){
			if(s.at(i)=='.'&&s.at(i+1)=='.'&&s.at(i+2)=='.') flg = 1;
		}
		if(!flg) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
}

