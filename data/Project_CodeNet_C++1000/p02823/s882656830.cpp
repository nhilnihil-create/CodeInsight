#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, a, b;
	cin >> n >> a >> b;
	if(abs(a-b)%2==0) {cout << abs(a-b)/2; return 0;}
	else{
		long long first,second;
		if((a-1)+(b-1) < (n-a) + (n-b)){
			first = min(a-1,b-1);
			second = max(a-1,b-1);
			}
		else{
			first = min(n-a,n-b);
			second = max(n-a,n-b);
		}
		long long result = 0;
		result += first;
		//cout << first << second;
		if (second - first == 1) {cout << result +1;return 0;}
		else cout << result + 1+(second-1-first)/2;
	}
 }
