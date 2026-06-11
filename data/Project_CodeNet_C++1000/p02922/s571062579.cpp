#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int A, B;
	cin >> A >> B;
	int tot = 1;
	for (int i = 0; i < 20; i++) {
		if (tot >= B) {
			cout << i << endl;
			return 0;
		}
		tot += A-1;	
	}
return 0;
}
