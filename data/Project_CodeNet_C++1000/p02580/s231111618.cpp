#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int h, w,m;
	cin >> h >> w >> m;

	vector<int> H(h),W(w);//各行、各列に含まれる要素数
	set<pair<int, int>> data;//爆破対象の配置
	int temp0, temp1;
	int max_h = 0, max_w = 0;
	rep(i, m) {
		cin >> temp0;
		temp0--;
		H[temp0]++;//各行の要素数をプラス
		if (H[temp0] > max_h) {//もしその行が最大の要素数ならmax_hにとる
			max_h = H[temp0];
		}
		cin >> temp1;
		temp1--;
		W[temp1]++;//各列の要素数をプラス
		if (W[temp1] > max_w) {//もしその行が最大の要素数ならmax_wにとる
			max_w = W[temp1];
		}
		data.insert({ temp0,temp1 });//爆破対象の格納
	}
	
	vector<int> H_max, W_max;
	for (int i = 0; i < h; i++) {//行iが最大の要素数ならH_maxに格納
		if (H[i] == max_h)
			H_max.push_back(i);
	}
	for (int i = 0; i < w; i++) {//列iが最大の要素数ならW_maxに格納
		if (W[i] == max_w)
			W_max.push_back(i);
	}
	//最大の要素数を持つ行と列の交点に爆破対象がないものを探す
	rep(i,H_max.size()){
		rep(j, W_max.size()) {
			if (data.count({H_max[i],W_max[j] }))//交点に爆破対象があれば探索続行
				continue;
			else {
				cout << max_h + max_w << endl;//交点に爆破対象が無ければ探索終了

				return 0;
			}
		}
	}
	cout << max_h + max_w - 1 << endl;

	return 0;
}