#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;
 
int main(){
	int n;
  	cin >> n;
  	
  	bool ans = false;
  	for(int i = 1; i < 10; i++){
    	if(n % i == 0 && n / i < 10) ans = true; 	
    }
  
  	if(ans) cout << "Yes" << endl;
  	else cout << "No" << endl;
}