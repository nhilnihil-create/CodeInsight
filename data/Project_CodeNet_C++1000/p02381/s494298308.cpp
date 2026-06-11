#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
/*n 人の学生を含むクラスでプログラミングの試験を行った。それぞれの得点をs1, s2 ... snとしたときの、標準偏差を求めるプログラムを作成せよ。
 */
using namespace std;

int main(){
	int n;
	double sum = 0;
	double subedSum = 0;
	cout << setprecision(30);
	while(true){
		vector<double> v;
		sum = 0;
		subedSum = 0;
		cin >> n;
		if(n == 0) return 0;
		for(int i = 0; i < n; i++){
			double tmp;
			cin >> tmp;
			v.push_back(tmp);
			sum += tmp;
		}
		double average = sum / n;
		for(int i = 0; i < n; i++){
			subedSum += (v[i] - average) * (v[i] - average);
		}
		cout << sqrt(subedSum / n) << '\n';
	}
}

