#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main() {
	int mf, df, ms, ds;
	cin >> mf >> df >> ms >> ds;
	if (ms == mf + 1 && ds == 1) {
		cout << '1' << endl;
	}
	else if (mf == 12 && df == 31) {
		cout << '1' << endl;
	}
	else {
		cout << '0' << endl;
	}
	return 0;
}