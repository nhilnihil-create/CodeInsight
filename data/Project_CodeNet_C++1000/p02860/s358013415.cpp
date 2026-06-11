#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; string s; cin >> n >> s;
  if (n&1){
	cout << "No" << "\n";
  }else{
	cout << ((s.substr(0,n/2) == s.substr(n/2)) ? "Yes" : "No") << "\n";
  }
   
return 0;
}
