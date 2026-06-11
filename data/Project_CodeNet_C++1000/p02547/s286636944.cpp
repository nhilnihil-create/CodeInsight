#include<iostream>
#include<vector>
using namespace std;



int main(){
	int n; cin >> n;
	vector<bool> v(n);

	for(int i=0; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[i] = (x == y);
	}
	
	bool flag = false;

	for(int i=0; i+2 < n; i++){
		flag |= v[i] && v[i+1] && v[i+2];
	}


	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}
