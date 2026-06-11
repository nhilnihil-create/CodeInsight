//
//AtCoder Beginner Contest 163
//D - Sum of Large Numbers
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define reAll(x) (x).rbegin(),(x).rend()

using ll = long long;

const int mod = 1000000007;

ll sum(ll l, ll r){
    return (l+r)*(r-l+1)/2;
}

int main()
{
    int n, k;
    cin >> n >> k;

    ll ans=0;
    for(ll i=k; i<=n+1; i++){
        ll l=sum(0,i-1);
        ll r=sum(n-i+1,n);
        ans += r-l+1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
