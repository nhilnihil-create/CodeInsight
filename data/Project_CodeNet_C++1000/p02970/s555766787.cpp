#include<iostream>
#include<cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,d;
	cin >> n >> d;
	int ans = ceil((float)n/(2*d+1));
	cout << ans;
	return 0;
}