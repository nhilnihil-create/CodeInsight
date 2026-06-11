#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n, d;
	cin >> n >> d;

	int range = 2*d+1;
	cout << (n+(range-1))/range << endl;

	return 0;
}
