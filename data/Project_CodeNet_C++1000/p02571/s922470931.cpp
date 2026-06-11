#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#define rep(i,n) for( int i = 0; i < n; i++)
using namespace std;
using ll = long long;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
ll u18 = 1000000000000000000;
int main()
{
    
	string s,t;
  cin >> s;
  cin >> t;
	
  int ans = t.size();
  for( int h = 0; h<= s.size()-t.size(); h++ ){
		int tmp = 0;
		for( int i = 0; i< t.size(); i++ ){
			if( s[h+i] != t[i] ) tmp ++;
		}	
		if( ans >= tmp ) ans = tmp;
	}	

	cout << ans << endl;
   
  return 0;
}
