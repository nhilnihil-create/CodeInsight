#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;
 
#define int long long
#define INF 1001001001

int arr[200001];
 
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

int32_t main() {
	
 	int A,B;
 	
 	cin >> A >>B;
 	
 	int res = -1;
 	for(int i=0; i<=INT_MAX; i++){
 		
 		int ans = floor(i*0.08);
 		int ans2 = floor(i*0.1);
 		
 		if(ans == A && ans2 == B){
 			res = i;
 			break;
		 }
		 else if( ans > A && ans2 > B){
 			break;
		 }
	 }
    
    
 	cout << res << endl;
 	
}