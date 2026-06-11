#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
const ll inf = 1e18;
int main()
{
    cin >> N;
    ll ans = inf;
    for(ll i = 1; i * i <= N; ++i){
        if(N % i == 0){
            ans = min(ans, i + N / i - 2);
        }
    }
    cout << ans << '\n';
    return 0;
}