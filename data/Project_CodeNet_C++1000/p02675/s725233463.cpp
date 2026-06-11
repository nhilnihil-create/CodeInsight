#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  
  string n;
  cin >> n;
  
  if(
     n[(int)n.size()-1] == '0' ||
     n[(int)n.size()-1] == '1' ||
     n[(int)n.size()-1] == '6' ||
     n[(int)n.size()-1] == '8'
     ) cout << "pon" << endl;
  else if(
	  n[(int)n.size()-1] == '3'
	  ) cout << "bon" << endl;
  else cout << "hon" << endl;
  
  return 0;
}
