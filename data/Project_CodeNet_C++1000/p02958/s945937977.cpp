#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(int &e : v)
		cin >> e;
	
	int cnt = 0;
	for(int i = 0;i < n;++i){
		cnt += (i+1 != v[i]);
	}

	cout << (cnt <= 2 ? "YES" : "NO"); 
}
