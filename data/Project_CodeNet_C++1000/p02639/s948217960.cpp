    #include <iostream>
    #include <vector>
    #include <string>
    #include <numeric>
    #include <tuple>
    #include <algorithm>
    #include <array>
    using namespace std;
    using ll = long long;
    #define rep(i,n) for(decltype(n) i=0; i<n; ++i)
    inline constexpr ll Inf = (1ULL << 62) -1;
     
    template <class T>
    void updatemax(T& a, T b) { if (b > a) a = b; }
     
    int main() {
      	ll x[5];
        ll ans=0;
        rep(i,5) cin >> x[i];
      	ans = 1 + find(begin(x), end(x), 0) - begin(x);
        cout << ans << endl;
        return 0;
    }