#include <bits/stdc++.h>
using namespace std;
const int M=200010;
string s[M];

int n , maxx = 0 , sum;

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i ++) cin >> s[i];
	
	sort(s + 1, s + n + 1 );
	
	for (int i = 1 , sum = 1 ; i <= n; i ++)
	if (s[i] != s[i + 1]){
		
		maxx = max(maxx, sum) ; sum = 1;
		
	}
	else sum ++;
	
	sum = 1;
	
	for (int i = 1 , sum = 1 ; i <= n; i ++)
	if (s[i] != s[i + 1]){
		
		if (sum == maxx){
			
			cout << s[i] << endl ; 
		}
		sum = 1;
	}
	else sum ++;
	return 0;
}