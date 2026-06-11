#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

using namespace std;

int main() {
	//freopen("0511.inp", "r", stdin);
	bool b[31]; memset(b, false, sizeof(b));
	loop(i, 0, 28) {
		int n; cin >> n;
		b[n] = true;
	}
	loop(i, 1, 31) if (!b[i]) cout << i << endl;
}