#include<bits/stdc++.h>
using namespace std;
long long solve (long long n, long long k){
	if(k == 0) return n;
	if(n >= k){
		long long rem = n % k;
		long long ans = min(rem, k - rem);  
		return ans;
	}		
}
int main(){
	long long n, k;
	cin >> n >> k;
	long long result = solve(n , k); 	
	cout << result << endl;
	return 0;
}