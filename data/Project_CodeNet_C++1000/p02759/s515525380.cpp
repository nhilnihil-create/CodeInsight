#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	//小数点以下を切り上げる時はfloor、切り捨てceil、四捨五入round
	//int型の切り上げ方法
	//2で割って切り上げる＝＞N+1/2
	//3で割って切り上げる＝＞N+2/3
	//4で割って切り上げる＝＞N+3/4
	printf("%d", (N + 1) / 2);

	return 0;
}