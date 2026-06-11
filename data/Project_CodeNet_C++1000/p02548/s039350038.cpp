#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	int answer = 0;
	for(int a = 1; a <= n; a++){
		for(int b = a; b < n; b += a){
			answer++;
		}
	}
	cout<<answer<<endl;
	return 0;
}

//a * b + c = n
// a * b = n - c