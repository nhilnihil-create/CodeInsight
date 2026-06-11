#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	int a[3][3];
  	rep(i, 3)rep(j, 3) cin >> a[i][j];
  	int n;
  	cin >> n;
  	rep(i, n){
    	int b;
      	cin >> b;
      
      	rep(j, 3)rep(k, 3){
        	if(a[j][k] == b) a[j][k] = 0;
        }
    }
  	
  	bool ans = false;
  	rep(i, 3){
    	if(a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) ans = true;
    }
  	rep(i, 3){
    	if(a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) ans = true;
    }
	if(a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) ans = true;
  	if(a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) ans = true;

  	if(ans) cout << "Yes" << endl;
  	else cout << "No" << endl;
}