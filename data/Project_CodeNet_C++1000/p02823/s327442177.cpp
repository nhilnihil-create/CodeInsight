#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n,a,b;
    cin >> n >> a >> b;
    // a-bが偶数: 間に収束
    // a-bが奇数: 一番上か一番下
    // 一番上か一番下で1つ止まってから進んでいく方法があった
    int64_t res;
    if(abs(a-b)%2 == 0){
        res = abs(a-b)/2;
    }else{
        int64_t topCount = abs(a-b)/2 + min(a,b);
        int64_t botCount = abs(a-b)/2 + n-max(a,b)+1;
        res = min(topCount, botCount);
    }
    cout << res << endl;
}