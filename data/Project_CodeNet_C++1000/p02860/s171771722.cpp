#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	string s;
  	cin >> n >> s;
  
  	bool ok = true;
  	if(n % 2 == 1) ok = false;
  	rep(i, n/2){
    	if(s[i] != s[i + n/2]) ok = false;
    }
  
  	if(ok) cout << "Yes" << endl;
  	else cout << "No" << endl;
}