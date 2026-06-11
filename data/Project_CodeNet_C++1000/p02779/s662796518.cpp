#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	int n;
  	cin >> n;
  	vector<int> a(n);
  	rep(i, n) cin >> a[i];
  	
  	bool ans = true;
  	sort(a.begin(), a.end());
  	rep(i, n){
		if(a[i] == a[i+1]){
        	ans = false;
          	break;
        }
    }
  
  	if(ans) cout << "YES" << endl;
  	else cout << "NO" << endl;
}