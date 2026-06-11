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
	
 	int N;
 	
 	cin >> N;
 	vector<int> v(N+1);
 	for(int i=1; i<=N; i++){		
 		int tmp;		
 		cin >> tmp;		
 		arr[tmp]++;	
 		v[i] = tmp;
	}
	
	int sum = 0;
	for(int i=1; i<=N; i++){		
		sum += choose2(arr[i]);	
		
	}
    int ans = sum;
    for(int i=1; i<=N; i++){
    	ans = sum;
    	ans -= choose2(arr[v[i]]);	
    	
    	ans += choose2(arr[v[i]]-1);
    	
    	cout << ans << endl;
	}
    
 	
 	
}