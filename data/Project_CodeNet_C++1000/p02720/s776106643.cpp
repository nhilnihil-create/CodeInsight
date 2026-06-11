#include<bits/stdc++.h>

#define ll long long

// 全探索の問題
// youtubeのほうは桁ごとに出している
// 解説はqueueを用いている
int main()
{
    ll K;
    std::cin >> K;

    std::vector<ll> a;
    for(int i=1; i <= 9; i++) {
        a.push_back(i);
    }

    ll count = 0;
    ll ans;
    while(true) {
        if(K <= a.size()) {
            std::cout << a[K-1] << std::endl;
            return 0;
        }
        K -= a.size();
        std::vector<ll> old;
        swap(old, a);
        for(ll x : old) {
            for(int i=-1; i <= 1; i++) {
                int d = x % 10 + i;
                if(d < 0 || d > 9) continue;
                ll nx = x * 10 + d;
                a.push_back(nx);
            }
        }
    }
    std::cout << ans << std::endl;
}