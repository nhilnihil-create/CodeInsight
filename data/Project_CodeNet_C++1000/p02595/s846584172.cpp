#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, d;
    cin >> n >> d;
    int count = 0;
    while(n--){
		long long x, y;
		cin >> x >> y;
		if (x * x + y * y <= d * d){
			count++;
			}
		}
	cout << count << endl;
}
