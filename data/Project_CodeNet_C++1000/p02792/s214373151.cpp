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
 
 int countDigit(int  n) 
{ 
    int k = 0; 
    while (n != 0) { 
        k = n%10; 
        n = n / 10; 
    } 
    return k; 
} 

 int arr[10][10];
int32_t main() {
 
 	int N;
 	
 	
 	cin >> N;
 	 
  
  	for(int i=1;i<=N; i++){
  		
  		int r = i%10;
  		int l = countDigit(i);
  		
  		
	  	arr[l][r]++;
	}
 	
 	int ans =0;
 	for(int i=0; i<=9; i++){
 		
 		for(int j=0; j<=9; j++){
 			
 			ans += arr[i][j] * arr[j][i];
 			
		}
		
	}
	 
	 
 	cout << ans << endl;
 	 
 	 
}