
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <tuple>

//#include <set>
//#include <unordered_map>
//#include <stack>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

#define max_n 100

long long T1, T2;
long long A1, A2;
long long B1, B2;


int main() {

	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	long long s1,s2;
	s1 = (A1 - B1)*T1;
	s2 = (A2 - B2)*T2;

	if ((s1 > 0 && s1 + s2 < 0) || (s1 < 0 && s1 + s2>0)) {
		if(abs(s1) % abs(s1 + s2)== 0)cout << (abs(s1) / abs(s1 + s2) + 1) * 2 - 2 << endl;
		else cout << (abs(s1)/abs(s1+s2)+1)*2 -1 << endl;
	}
	else if(s1 + s2 == 0){
		cout << "infinity" << endl;
	}
	else cout << "0" << endl;
	

	

	return 0;
}
