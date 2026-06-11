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


double expectedValue(int value){
	double sum = 0;
	double div = 1.0 / value;
	for(int i=1; i<=value; i++){	
		sum = sum + (i*div);
	}
	return sum;
}
 int arr[200001];
int32_t main() {
 
   int N,K;
   
   cin >> N >>K ;
   
   for(int i=0; i<N; i++){
   	
   		cin >> arr[i];
   	
   }
   
    int maxi = 0;
    int index = 0;
   for(int i=0; i<N; i++){
   		int sum = 0;
   		if(i+K > N){
   			break;
		}
   		for(int j=0; j<K; j++){
   			
		   	sum+= arr[i+j];
   			
		}
   		if(sum > maxi){
   			maxi = sum;
   			index = i;
		}
   } 
  // cout << index << endl;
    double ans = 0;
 	for(int i = 0; i < K; i++){
 		
 		ans += expectedValue(arr[i+index]);
 		
	 }
 	cout << fixed << setprecision(12) <<  ans << endl;
}