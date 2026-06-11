typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,k;
    std::cin >> n>>k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        vector<ll> imos(n+1,0);
        vector<ll> imos2(n+1,0);
        for (int j = 0; j < n; j++) {
            imos[max(0ll,j-a[j])]++;
            imos[min(n,j+a[j]+1)]--;
        }
        ll minv = 1e15;
        for (int j = 0; j < n; j++) {
            imos2[j+1] = imos2[j]+imos[j];
            a[j] = imos2[j+1];
            minv = min(minv,a[j]);
        }
        if(minv==n)break;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << a[i]<<" ";
    }
    std::cout  << std::endl;
}