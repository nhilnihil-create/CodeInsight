#include <iostream>

using namespace std;

int main(){
	int n,k,q;
	cin >> n >> k >> q;
	
	int a[q];
	int points[n];
	for(int i = 0; i < n; i++) points[i] = k-q;
	for(int i = 0; i < q; i++){
		cin >> a[i];
		points[a[i]-1]++;
	}
	for(int i = 0; i < n; i++) {
//		cout << points[i] << endl;
		if(points[i] > 0) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
	return 0;
}