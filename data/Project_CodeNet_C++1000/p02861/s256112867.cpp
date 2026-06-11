#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

const ll MAX = 110000;
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline long long factorial(T N) {
    int ans = 1;
    for (int i = 1; i <= N; ++i) {
        ans *= i;
    }
    return ans;
}

vector<int> x(10), y(10);

double distance(int i, int j) {
    double dx, dy;
    dx = x[i] - x[j];
    dy = y[i] - y[j];
    return pow(pow(dx, 2) + pow(dy, 2), 0.5);
}

int main() {
    int N; cin >> N;
    vector<int> v(N);
    int fac = 1;
    double sum = 0.0;
    //初期条件
    x[0] = 0; y[0] = 0;
    
    for (int i = 1; i <= N; ++i) cin >> x[i] >> y[i];

    //ノード(0 ~ N-1) を作成
    for (int i = 0; i < N; ++i) {
        v[i] = i + 1;
    }
    //N!の計算
    fac = factorial(N);
    //ノード(i), ノード(i + 1)までの、エッジの総和を計算
    do {
        for (int i = 0; i < N-1; ++i) {
            sum += distance(v[i], v[i + 1]);
        }
    } while (next_permutation(v.begin(), v.end())); //順列
    //エッジの平均値を計算・出力(浮動小数点6桁以下)
    cout << fixed << setprecision(6) << (sum / fac) << '\n';

    return 0;
}