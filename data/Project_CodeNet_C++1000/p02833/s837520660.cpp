#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// 10 で割り切れる <==> 2 で割り切れる かつ 5 で割り切れる
// f(N) が 2 で割り切れる回数と f(N) が 5 で割り切れる回数の min を求めればよい。
int main()
{
    ll N;
    cin >> N;
    if (N & 1) // 奇数の時、f(N) も奇数なので、2で割り切ることができない。よってゼロが答え。
    {
        cout << 0 << endl;
        return 0;
    }
    // 偶数の時, 二重階乗の性質より
    // min = (5で割り切れる回数)
    ll ans = 0;
    ll deno = 10;
    while(deno <= N)
    {
        ans += N / deno;
        deno *= 5;
    }
    cout << ans << endl;
    return 0;
}
