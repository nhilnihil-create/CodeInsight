#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, D;
	cin >> N >> D;
	int a, b, c = 0;
	for(int i = 1; i<=N; ++i){
		cin >> a >> b;
		if(sqrt(pow(a, 2) + pow(b, 2)) <= D){
			c++;
		}
	}
	cout << c;
}
