#include"bits/stdc++.h"
using namespace std;
int main(){
	string s; cin >> s;
    string copy = s;
  	reverse(copy.begin(),copy.end());
	int res = 0;
  	for (int i = 0 ; i < s.size() ; i++) {
    	res += (s[i] != copy[i]);
    }
  	cout << res/2 << endl;
}