#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	string n;
	cin >> n;

	if (n[2]==n[3] && n[4]==n[5]) {
		cout <<"Yes"<< endl;
	}
	else{
		cout << "No" << endl;
	}


	

	return 0;
}