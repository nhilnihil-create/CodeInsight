#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	float side = (float)n/3;
	cout << fixed << setprecision(8) << side*side*side;
	return 0;
}