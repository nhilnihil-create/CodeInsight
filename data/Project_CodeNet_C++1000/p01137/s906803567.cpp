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
  int e;
  while( cin >> e, e ) {
    /*int m = 0;
    int ans;
    int sum = 0;
    
    for(int i=0; ; i++) {
      if( pow(i, 3) > e ) { sum += pow(i-1, 3); m += i-1; break; }
    }
    
    for(int i=0; ; i++) {
      if( pow(i, 2) > e-sum ) { sum += pow(i-1, 2); m += i-1; break; }
    }
    
    ans =  m + e-sum;
    
    m = sum = 0;

    for(int i=0; ; i++) {
      if( pow(i, 2) > e ) { sum += pow(i-1, 2); m += i-1; break; }
    }
    
    for(int i=0; ; i++) {
      if( pow(i, 3) > e-sum ) { sum += pow(i-1, 3); m += i-1; break; }
    }
    
    cout << min( ans, m + e-sum ) << endl;
    */
    int mi = INF;
    for(int i=0; i<1000; i++) {
      for(int j=0; j<1000; j++) {
	int tmp = j*j + i*i*i;
	if( tmp <= e ) {
	  mi = min( mi, i + j + (e-tmp) ); 
	}
      }
    }

    cout << mi << endl;
    
  }
  
}