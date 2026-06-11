#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;	
	cin >> n;

	vector<int> v(n);
	for(int &e : v)
		cin >> e;
	
	int xD = INT_MAX;	
	int left = 0, right = accumulate(v.begin(), v.end(), 0);
	xD = right;
	for(int e : v){
		left += e;
		right -= e;		
		xD = min(xD,abs(left-right));
	}
	cout << xD;
}
