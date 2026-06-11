#include <iostream>
#define int long long
using namespace std;

signed main() {
	int t1, t2, a1, a2, b1, b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	
	//bから見たaの相対速度
	int c = a1 - b1;
	int d = a2 - b2;
	
	//標準化. c < 0なら, aから見たbの相対速度にする (グラフを反転)
	if (c < 0) {
		c = -c;
		d = -d;
	}
	
	//相対位置のグラフの形は3パターン.
	//これは1周期ごとの相対位置の変化量sによって判別
	int s = c * t1 + d * t2;
	
	if (s > 0) {	//上向き. x軸と交差しない.
		cout << 0 << endl;
	}
	else if (s == 0) {
		cout << "infinity" << endl;
	}
	else {	//下向き. 基本的に1周期あたり2回交差.
			//ただし, 1回だけ1回交差するパターンがあり得る。
		int q = -d * t2;	//1回あたりの下降量(正にする)
		s = -s;				//sを正の値にしておく
		
		//q > nsなる最大のnを取ると、n回2回交差が起きる.
		//n < q / s
		//ここでn = [q / s]とすると、基本的に最大のnだが、
		//q % s == 0のときだけ1回余計に足すことになるので、足しすぎた分を引く.
		
		int cnt = 2 * (q / s) - (q % s == 0);
		
		//また、時刻0の分は数えないので、1引く
		cnt--;
		
		cout << cnt << endl;
	}
	return 0;
}