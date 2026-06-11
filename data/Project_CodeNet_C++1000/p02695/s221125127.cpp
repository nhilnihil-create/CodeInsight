#include <queue>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <time.h>
#include <functional>

//#include "All.h"

using namespace std;
typedef long long int ll;

#define EPS (1e-9)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(int i=0;i<n;i++)

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    REP(i, b) tmp *= a;
    return tmp;
}

ll N, M, Q;
ll a[110], b[110], c[110], d[110];
ll A[10000010][11] = {};

ll X[110] = {};

ll ai = 0;

ll n = 0;

ll ans = -1;

void Amaker(ll e, ll M, ll n) {
    //aはn回めのループの最初のインデックス
    //Nはループの回数
    //nは今何回目繰り返したかを数える
    //n回再帰的に繰り返す
    for (ll i = e; i < M; i++) {
        //X[]は各ループのインデックスを覚えておく
        X[n] = i;
        //cout << "X[" + to_string(n) + "]:" + to_string(i + 1) << endl;
        if (N - 1 == n) {
            //やりたい処理
            //X[n]がn + 1回めのインデックスを表す
            REP(j, N) {
                A[ai][j] = X[j] + 1;
                //cout << X[j] + 1 << " ";
            }
            //cout << endl;
            ai++;
        }
        else {
            Amaker(i, M, n + 1);
        }
        //if (L - 1 == i) n--;
    }
}

int main() {
    cin >> N >> M >> Q;
    REP(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    //まず全てのA配列の可能性を書き出す
    //Amaker(0, 3);
    //cout << endl;
    //REP(i, ai) {
    //    REP(j, 3) {
    //        cout << A[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    Amaker(0, M, 0);

    //REP(i, 4) {
    //    Amaker(0, i + 1);
    //    cout << endl;
    //}

    ll tmp;

    REP(i, ai) {
        //ai番目の数列に対して
        tmp = 0;
        REP(j, Q) {
            //Q個あてはめていくつ点が取れるかみる
            if (A[i][b[j] - 1] - A[i][a[j] - 1] == c[j]) tmp += d[j];
            //cout << to_string(A[i][b[j] - 1]) + " " + to_string(A[i][a[j] - 1]) << endl;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

}

/*
10 10 2
1 10 9 1
2 10 9 2
*/
