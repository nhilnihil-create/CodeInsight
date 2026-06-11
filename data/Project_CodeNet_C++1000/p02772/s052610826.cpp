#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, a;
	cin >> N;
	vector<int> A;
	for(int i=0;i<N;i++){
		cin >> a;
		if(a % 2 == 0){
			A.push_back(a);
		}
	}

	for(auto num:A){
		if(num % 3 != 0 && num % 5 != 0){
			cout << "DENIED" << endl;
			return 0;
		}
	}
	cout << "APPROVED" << endl;

}
