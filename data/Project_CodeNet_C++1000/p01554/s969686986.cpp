#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

  long long int n;

  while( cin >> n ) {

    vector< string > id;

    for ( long long int i = 0; i < n; i++ ) {

      string in;
      cin >> in;
      id.push_back( in );

    }

    sort( id.begin(), id.end() );

    long long int m;
    cin >> m;

    long long int k = 0;

    for ( long long int i = 0; i < m; i++ ) {

      string in;
      cin >> in;

      if ( binary_search( id.begin(), id.end(), in ) ) {
	if ( k == 0 ) {
	  k = 1;
	  cout << "Opened by " << in << endl;
	}else {
	  k = 0;
	  cout << "Closed by " << in << endl;
	}
      }else {
	cout << "Unknown " << in << endl;
      }

    }

  }

  return 0;

}