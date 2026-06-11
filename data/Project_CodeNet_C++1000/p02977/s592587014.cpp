#include <iostream>
#include <set>

using namespace std;
set<int> s;
int main(){
	int i,j,n;
	cin >> n;
	int res = 1;
	for(i=0;i<=20;i++){
		s.insert(res); res *= 2;
	}
	if(s.count(n)){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	cout << 1 << " " << 2 << endl;
	cout << 2 << " " << 3 << endl;
	cout << 3 << " " << 1 + n << endl;
	cout << 1 + n << " " << 2 + n << endl;
	cout << 2 + n << " " << 3 + n << endl;
	if(n==3) return 0;
	int l = 3 + n;
	for(i=4;i<=n - 3;i+=4){
		cout << l << " " << i << endl;
		cout << i << " " << i + 1 << endl;
		cout << i + 1 << " " << i + 2 << endl;
		cout << i + 2 << " " << i + 3 << endl;
		cout << i + 3 << " " << i + n << endl;
		cout << i + n << " " << i + n + 1 << endl;
		cout << i + n + 1 << " " << i + n + 2 << endl;
		cout << i + n + 2 << " " << i + n + 3 << endl;
		l = i + n + 3;
	}
	if(n%4==0){
		cout << n << " " << n - 4 << endl;
		cout << 2*n << " " << (n^(n-4)) + 1 << endl;
	}
	if(n%4==1){
		cout << n - 1 << " " << n << endl;
		cout << n << " " << 1 << endl;
		cout << 1 << " " << 2*n - 1 << endl;
		cout << 2*n - 1 << " " << 2*n << endl;
	}
	if(n%4==2){
		cout << n << " " << n - 1 << endl;
		cout << n - 1 << " " << 3 << endl;
		cout << n - 2 << " " << n - 1<< endl;
		cout << 3 << " " << 2*n << endl;
		cout << 2 << " " << 2*n - 2 << endl;
		cout << 2*n - 2 << " " << 2*n - 1 << endl;
	}
}