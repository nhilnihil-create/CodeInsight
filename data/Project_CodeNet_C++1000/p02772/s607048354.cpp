#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	bool ans = true;
  	rep(i, n){
    	int a;
      	cin >> a;
      	if(a % 2 == 0){
        	if(a % 3 == 0 || a % 5 == 0) continue;
          	else {
              ans = false;
              break;
            }
        }  
    }
  	
 	if(ans) cout << "APPROVED" << endl;
  	else cout << "DENIED" << endl;
}