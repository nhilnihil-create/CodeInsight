#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n,i =0,k;
	cin >> n;
	vector<int>a(n+1);
	rep(i, n-1) {
		cin >> k;
		a.at(k)++;
	}
	rep2(i,1, n+1) {
		cout << a.at(i) << endl;
	}
	
	return 0;
}
