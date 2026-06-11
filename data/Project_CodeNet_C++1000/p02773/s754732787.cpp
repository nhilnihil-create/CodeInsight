#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	map<string, int> a;
  	rep(i, n){
      	string s;
    	cin >> s;
      	a[s]++;
    }
  
  	int mx = 0;
  	for(auto x : a){
    	mx = max(mx, x.second);
    }
  
  	for(auto x : a){
    	if(x.second == mx) cout << x.first << endl;
    }
}