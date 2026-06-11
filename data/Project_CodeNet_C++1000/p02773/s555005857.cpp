#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include<algorithm>
#include<map>
#include <queue>
#include <set>
using namespace std;
 
#define int long long
#define INF 1001001001
 
int nChoosek( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
        result %= 1000000007;
    }
    return result;
}

int choose2(int n){
	
	return n*(n-1)/2;
}

map<string, int> m; 

set<string> st;
int32_t main() {
 
  	int N;
  	int maxi = 0;
  	cin >> N;
  	for(int i=0; i<N; i++){
  		
  		string s;
		  
		cin >> s;
		
		m[s]++; 
	   	st.insert(s);
	   	maxi = max(maxi,m[s]);
	}
 	
 	
 	for(auto f : st) {
	  
	  if(m[f] == maxi){
	  	cout << f << endl;
	  }
	  
	  
	}    
 	
   
}