#include <bits/stdc++.h>
using namespace std;

#define ll long long

int foo(int A){
	int ct = 0;
	for (int j = 1; j*j <= A; j ++){
		if (A % j == 0){
			int f1 = j, f2 = A / j;
			if (f1 == f2) ct += 1;
			else ct += 2;
		}
	}
	return ct;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	ll result = 0;
	for (int i = 1; i <= N - 1; i ++){
		result += foo(i);
	}
	cout << result << "\n";

}