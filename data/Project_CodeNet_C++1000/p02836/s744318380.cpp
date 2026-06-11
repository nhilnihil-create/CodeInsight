#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	string s;
  	cin >> s;
  	
  	int l = 0;
  	int r = s.size() - 1;
  	int ans = 0;
 	rep(i, r){
    	if(s[l] != s[r]){
          s[l] = s[r];
          ans++;
        }
      	l++;
      	r--;
    }
  
  	cout << ans << endl;
}