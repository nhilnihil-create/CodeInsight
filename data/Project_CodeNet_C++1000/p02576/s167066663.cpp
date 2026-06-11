#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, X, T;
	cin >> N >> X >> T;
	float one = (float)T/(float)X;
	int a= ceil(((float)N*one)/(float)T);
	int ans = T * a;
	cout << ans; 	
}

