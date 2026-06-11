#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, d;
	cin >> n >> d;
	long long count = 0;
	while(n--){
		long long x, y;
		cin >> x >> y;
		if(sqrt((x * x) + (y * y)) <= d){
			count++;
		}
	}
	cout << count << endl;
}

