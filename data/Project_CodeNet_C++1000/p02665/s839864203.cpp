typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n+1);
    vector<ll> asum(n+2,0);
    for (int i = 0; i < n+1; i++) {
        std::cin >> a[i];
        asum[i+1] = asum[i]+a[i];
    }
    
    vector<ll> cnt(n+1,0);
    cnt[0] = 1;
    ll sum = 1;
    cnt[0]-=a[0];
    if(n==0&&a[0]!=1){
        std::cout << -1 << std::endl;
        return 0;
    }
    for (int i = 1; i < n+1; i++) {
        cnt[i] = min(asum[n+1]-asum[i+1],cnt[i-1]*2-a[i]);
        sum += a[i];
        if((cnt[i]<=0&&i!=n)||cnt[i]<0){
            std::cout << -1 << std::endl;
            return 0;
        }
        if(i!=n)sum += cnt[i];
    }
    std::cout << sum << std::endl;
}
