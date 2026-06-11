#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	int n;
  	string s;
  	cin >> n >> s;
  
  	if(n % 2 != 0){
      cout << "No" << endl;
      return 0;
    }
  
  	string t1, t2;
  	rep(i, n){
      if(i < n/2) t1.push_back(s.at(i));
      else t2.push_back(s.at(i));
    }
  
  	if(t1 == t2) cout << "Yes" << endl;
  	else cout << "No" << endl;
  	return 0;  
}
