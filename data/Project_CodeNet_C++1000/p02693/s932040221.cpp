#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define gap ' '
#define L(i) ((i) - (&i))

const int MAXN = 1e7 + 5;
	
int main(){	
	int k; cin >> k;
	int a, b; cin >> a >> b;
	for(int i = a; i <= b; ++i){
		if(i % k == 0){
			cout << "OK" << endl; return 0;
		}
	}
	cout << "NG" << endl;


	return 0;
}
