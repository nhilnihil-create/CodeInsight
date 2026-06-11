#include <iostream>
using namespace std;

int a[200010];

int main() {
	int N;
	cin >> N;
	int xsum=0;
	for(int i=0; i<N; ++i){
		cin >> a[i];
		xsum ^= a[i];
	}
	cout << (xsum^a[0]);
	for(int i=1; i<N; ++i) cout << ' ' << (xsum^a[i]);
	cout << endl;
	return 0;
}