// ※※※ 解答不能 ※※※
// j_taka_z 氏.
// https://atcoder.jp/contests/ddcc2020-qual/submissions/8594243
// -> 解説通りだったので, 暗記.
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    LL m, D = 0, S = 0, d, c;
    scanf("%d", &m);
    rep(i, m){
        scanf("%lld %lld", &d, &c);
        D += c;
        S += d * c;
    }
    printf("%lld\n", D - 1 + (S - 1) / 9);
    return 0;
}