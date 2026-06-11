#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n%2 == 1){
		cout << "No" << endl;
		return 0;
	}
	else{
		rep(i,n/2){
			if(s[i] != s[i+n/2]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}