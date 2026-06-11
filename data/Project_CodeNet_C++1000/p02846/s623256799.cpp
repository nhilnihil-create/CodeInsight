#include <iostream>
using namespace std;

#define OUTINF "infinity"

int main(void) {
	long long T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	// T1+T2経過後の位置
	A1 = A1*T1, A2 = A2*T2;
	B1 = B1*T1, B2 = B2*T2;
	if ((A1+A2)<(B1+B2)) {swap(A1,B1); swap(A2,B2);}
	// 差がつかない
	if ((A1==B1) || ((A1+A2)==(B1+B2))) {
		cout << OUTINF << endl;
		return 0;
	}
	// 一度も交差しない
	if ((A1-B1)>0) {
		cout << 0 << endl;
		return 0;
	}

	// 2回目のT1での差
	long long T1T1dif = 2*(A1-B1)+(A2-B2);
	// T1-T1間で縮まる距離
	long long interval = (A1-B1)-T1T1dif;
	long long cnt = ((A1-B1)/interval)*2 + 1; // x2足す分
	if (((A1-B1)%interval)==0) { // 最後の1回が追い抜かない
		cnt -= 1;
	}
	cout << cnt << endl;
	return 0;
}
