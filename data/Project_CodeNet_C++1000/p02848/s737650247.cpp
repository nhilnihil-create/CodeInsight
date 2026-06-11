#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	string s;
  	cin >> n >> s;
  
  	rep(i, s.size()){
      	if(s[i] + n > 90) s[i] = 'A'+(s[i]+n-91);
    	else s[i] = s[i] + n;
    }
  
  	cout << s << endl;
}