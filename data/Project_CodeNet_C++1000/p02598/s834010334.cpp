#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> data(n);
	rep(i, n)
		cin >> data[i];
	//K回以内にあるlengthで切ることが出来たらokとする。出来なかったらngとする。
	//1<<data[i]<<1e9なので、開始はng=0、ok=1e9+1とする。
	int ng = 0, ok = 1e9 + 1;
	while (ok - ng != 1) {
		int mid = (ng + ok) / 2;
		int cut_count = 0;
		for (int i = 0; i < n; i++) {
			cut_count += data[i] / mid;
			if (data[i] % mid == 0)
				cut_count--;
			if (cut_count > k)
				break;
		}
		if (cut_count > k) {
			ng = mid;
			//cout <<"ng="<< ng << endl; 確認用
		}
		else {
			ok = mid;
			//cout << "ok=" << ok << endl; 確認用
		}
	}

	cout << ok << endl;
	return 0;
}