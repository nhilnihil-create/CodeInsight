#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
signed main()
{
  int k;
  string s;
  cin >> k >> s;
  if(s.length() <= k){
      cout << s << "\n";
      return 0;
  }else{
      cout << s.substr(0,k) << "..." << "\n";
  }
}