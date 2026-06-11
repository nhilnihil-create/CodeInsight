#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long k, q;
    cin >> k >> q;
    vector<unsigned long> d(k);
    for(auto& i : d)cin >> i;
    const auto& query = [&](unsigned long n, unsigned long x, unsigned long m) -> unsigned long {
        unsigned long S{x + n}, c{n + k - 1};
        for(const auto& i : d)S += c-- / k * ((i + m - 1) % m);
        return n - S / m + x / m;
    };
    for(unsigned long i{0}, n, x, m; i < q; ++i){
        cin >> n >> x >> m;
        cout << query(n - 1, x, m) << endl;
    }
    return 0;
}