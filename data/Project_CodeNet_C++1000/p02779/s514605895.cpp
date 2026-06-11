#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
 
#define int long long
#define INF (1e18)+1
 
int nChoosek( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i; 
    }
    return result;
}

int choose2(int n){
	
	return n*(n-1)/2;
}

map<int ,int> m;

int32_t main() {
 
   
   	int N;
	   
	cin >> N;
	bool flag = true;
	for(int i=0; i<N; i++){
		
		int tmp;
		cin >> tmp;
		
		m[tmp]++;
		
		if(m[tmp] > 1){
			flag = false;
			break;
		}
		
	}	
   	
   if(flag){
   	cout << "YES" << endl;
   }
   else{
   	cout << "NO" << endl;
   }
   
   
   
   
 
}