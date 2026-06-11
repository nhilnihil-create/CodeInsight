#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	string s;
  	cin >> s;
  
  	bool ok = true;
  	rep(i, s.size()){
    	if(i % 2 == 0 && s[i] == 'L') ok = false;
        if(i % 2 == 1 && s[i] == 'R') ok = false;  
    }
  
  	if(ok) cout << "Yes" << endl;
  	else cout << "No" << endl;
}