/*
 * じょえチャンネル
 * 高評価・チャンネル登録よろしくお願いします！
 * https://www.youtube.com/channel/UCRXsI3FL_kvaVL9zoolBfbQ
 */

#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long k, q;
    cin >> k >> q;
    vector<unsigned long> d(k);
    for(auto& i : d)cin >> i;
    const auto& query = [&](unsigned long n, unsigned long x, unsigned long m) -> unsigned long {
        x %= m;
        unsigned long S{0}, c{0};
        for(unsigned long i{0}; i < k; ++i){
            auto coef = (n + k - i - 2) / k;
            S += d[i] % m * coef;
            c += !!(d[i] % m) * coef;
        }
        return c - (S + x) / m + x / m;
    };
    for(unsigned long i{0}, n, x, m; i < q; ++i){
        cin >> n >> x >> m;
        cout << query(n, x, m) << endl;
    }
    return 0;
}