#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

// 構造体を定義
struct work {
    int a;
    int b;
};

// 比較関数を定義
bool comp_work(const work& left, const work& right) {
    return left.b == right.b ? left.a < right.a : left.b < right.b;
}

int main() {
	int n;
	//入力
	cin >> n;
	vector<work> w(n);
    rep(i, n) {
        cin >> w[i].a >> w[i].b;
    }
    //終了時刻でsort
    sort(w.begin(), w.end(), comp_work);

    /* 作業時間を加算して終了時刻と比較 */
    int total = 0;
    int flg = 0;
    rep(i,n) {
        total += w[i].a;
        if (total > w[i].b) {
            ++flg;
            break;
        }
    }
    if (flg==0)
    	std::cout << "Yes" << endl;
    else
        std::cout << "No" << endl;
}
