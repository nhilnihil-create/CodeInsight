#include <bits/stdc++.h>

using namespace std;

int n, p;
int a, b[53];

int main(){
	while (cin >> n >> p){
		if (!n&!p) break;
		for (int i = 0; i < 53; i++) b[i] = 0;
		int i = 0;
		a = p;
		while (true){
			if (a > 0) {
				b[i]++; a--;
			}
			else if (a == 0){
				a = b[i]; b[i] = 0;
			}
			if (b[i] == p) break;
			if (i == n - 1) i = 0;
			else i++;
		}
		cout << i << endl;
	}
}