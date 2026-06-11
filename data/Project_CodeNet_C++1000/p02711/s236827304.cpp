#include<bits/stdc++.h>
using namespace std;

signed main()
{
  char n; 
  for(int i = 0 ; i<3; ++i){
    cin >> n;
    if(n=='7') {
      cout << "Yes";
      return 0;
    }
  }

  cout << "No";
}