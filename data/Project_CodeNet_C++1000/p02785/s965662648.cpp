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

int arr[200001];

 
int32_t main() {
 
   int N,K ;
   
   cin >> N >> K;
   
   for(int i=0; i<N; i++){
   		
   		cin >> arr[i];
   	
   	
   }
   
   sort(arr, arr+N);
   
   reverse(arr,arr+N);
   
   int cnt = 0 ;
   for(int i=0+K; i<N; i++){
   	
   		cnt+= arr[i];
   	
   }
   
   
   cout << cnt << endl;
   
}