#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	int n, student[1000];
	double a = 0,standard=0;

	//生徒数
	cin >> n;

	//生徒数が0以外で実行
	while (n != 0) {

		for (int i = 0; i < n; i++) {
			//点数入力
			cin >> student[i];
			//平均点
			standard += student[i];
		}

		//平均点s
		standard /= n;
		
		for (int i = 0; i < n; i++) {
			a += powl(student[i] - standard, 2);
		}
		a /= n;
		a = sqrtl(a);

		//偏差出力
		cout << fixed << setprecision(8) << a << endl;
		
		//初期化
		a = 0, standard = 0;

		//もう一度生徒数入力
		cin >> n;
	}


	return 0;
}
