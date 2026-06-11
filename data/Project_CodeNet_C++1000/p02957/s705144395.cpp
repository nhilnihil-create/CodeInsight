#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	int MI = min(A, B), MX = max(A, B);	
	for(int i=MI;i<=MX;i++){
		if(abs(A - i) == abs(B - i)){
			cout << i << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}