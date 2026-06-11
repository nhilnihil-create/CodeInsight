#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    ll M;
    cin >> M;
    ll cnt, sum;
    cnt = sum = 0;
    rep(i, 0, M)
    {
        ll d, c; 
        cin >> d >> c;
        cnt += c;
        sum += d*c;
    }
    // cout << 9*cnt + sum << endl;
    ll num = 9LL*cnt + sum;
    ll ans = num/9 - 1 - int(num%9 == 0) ;
    cout << ans << endl;
    return 0;
}