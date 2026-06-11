#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  	int n;
  	string s;
  	cin >> n >> s;
  
  	int ans=1;
  	rep(i, n-1){
      if(s.at(i) != s.at(i+1)) ans++;
    }
  
  	cout << ans << endl;
  	return 0;  
}
