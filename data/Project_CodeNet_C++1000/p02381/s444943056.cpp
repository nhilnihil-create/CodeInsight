#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){

	double students[1001] = {0};
	double n, sum, ave, DeviationSum, StandardDeviation;

	cin >> n;
	while( n > 0 ){
		/* 要素の代入と合計値:sumと平均値:aveと偏差の和:deviationSumを宣言 */
		sum = ave = DeviationSum = 0;
		for(int i = 1; i <= n; i++){
		cin >> students[i];
		sum += students[i];
		}
		ave = sum / n;

		/* 偏差(deviation)の計算 */
		for(int i = 1; i <= n; i++){
			DeviationSum += pow(students[i]-ave,2);
		}

		/* 標準偏差(standard deviation)の計算 */
		StandardDeviation = sqrt(DeviationSum/n);

		printf("%.8f\n", StandardDeviation);
		cin >> n;
	}

	return 0;
}

/******************************************************************/
//注意点↓↓↓↓

//文章では、平均はmで宣言している
//プログラム上では、ave に変更している。

//用語の説明↓↓↓↓

//偏差(deviation)とは、個々の数値と平均値との差のことです。
//個々のデータが平均値から偏っている程度を表しています。
//偏差 = si - ave 
// siは個々の数値
// aveは平均値


//ここも重要点↓↓↓↓

//分散(dispersion)：偏差の二乗平均
//標準偏差(StandardDeviation)：正の偏差の二乗平均の平方根

/******************************************************************/
