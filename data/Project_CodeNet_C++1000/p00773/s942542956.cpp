#include<bits/stdc++.h>
using namespace std;

main()
{
  int x, y, s;
  while( cin >> x >> y >> s, x + y + s ) {
    int mx = 0;
    for(int i=1; i<s-1; i++) {
      for(int j=i; j<s; j++) {
	if( i * (100+x) / 100 + j * (100+x) / 100 == s ) {
	  mx = max(mx, i * (100+y) / 100 + j * (100+y) / 100); 
	}
      }
    }

    cout << mx << endl;
  }
}