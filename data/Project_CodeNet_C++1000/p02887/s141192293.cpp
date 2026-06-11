#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	string s;
  	cin >> n >> s;
  
  	int ans = 0;
	rep(i, n){
      	int j = i+1;
    	while(s[i] == s[j]){
        	j++;
        }
      	ans++;
      	i = j-1;
    }
  
	cout << ans << endl;
}