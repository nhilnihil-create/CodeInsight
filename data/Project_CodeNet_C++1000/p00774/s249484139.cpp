#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;


main()
{
  int H;
  while( cin >> H, H ) {
    int data[11][5];

    Rep(i, H) Rep(j, 5) cin >> data[i][j];

    int sum = 0;
    while( 1 ) {
      bool flag = false;
    
      Rep(i, H) Rep(j, 5) {
	if( data[i][j] == 0  ) continue;
	int r = j+1;
	while( r < 5 ) {
	  if( data[i][j] != data[i][r] ) break;
	  r++;
	}
	if( r - j >= 3 ) {
	  //cout << i << " " << j << " " << r << endl;
	  sum += (r - j) * data[i][j];
	  for(int k=j; k<r; k++) data[i][k] = 0;
	  flag = true;
	}
      }

      if( flag ) {
	bool flag2 = true;
	while( flag2 ) {
	  flag2 = false;
	  for(int i=H-1; i>0; i--) {
	    for(int j=0; j<5; j++) {
	      if( data[i][j] == 0 && data[i-1][j] != 0 ) {
		flag2 = true;
		data[i][j] = data[i-1][j];
		data[i-1][j] = 0;
	      }
	    }
	  }
	}
      } else {
	break;
      }
    }

    cout << sum << endl;
  }
}