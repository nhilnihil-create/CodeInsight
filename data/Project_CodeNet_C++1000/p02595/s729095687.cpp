#include<iostream>
#include<vector>
using namespace std;



int main() {

	int n,d; cin >> n>>d;
	vector<int>v; int count = 0; double sum=0;
	for (int i = 0; i < n; i++) {
		int input1, input2; cin >> input1 >> input2;
		v.push_back(input1); v.push_back(input2);
		sum = sqrt(pow(input1, 2) + pow(input2, 2));
		if(sum <= d)
			count++;
		sum = 0;
		v.clear();
	}
	cout << count;



}