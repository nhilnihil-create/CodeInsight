#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,m;
	cin >> n >> m;
	for(long long i=1,j=m+1;i<j;i++,j--){
		cout << i << " " << j << endl;
	}
	for(long long i=m+2,j=2*m+1;i<j;i++,j--){
		cout << i << " " << j << endl;
	}
} 
