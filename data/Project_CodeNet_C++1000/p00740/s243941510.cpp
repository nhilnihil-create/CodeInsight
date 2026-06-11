#include <bits/stdc++.h>
using namespace std;

int n, p;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	while(1){
		cin >> n >> p;
		if(n == 0 && p == 0) return 0;
		int a[n] = {};
		int t = p;
		int cnt = 0;
		while(1){
			if(t > 0){
				--t;
				++a[cnt%n];
				if(t == 0 && a[cnt%n] == p){
					cout << cnt%n << "\n";
					break;
				}
			}else{
				t += a[cnt%n];
				a[cnt%n] = 0;
			}
			++cnt;
		}
	}
}
