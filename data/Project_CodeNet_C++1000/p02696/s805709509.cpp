#include <bits/stdc++.h>
using namespace std;
int main(){
	long long A, B, N;
	cin >> A >> B >> N;
	long long M = B-1;
	if(M > N) M = N;
	long long ans = (M * A) / B;
	cout << ans << endl; 
}
