/*
 * @Author: AsilenceBTF
 * @Buff: ︿(￣︶￣)︿  芜湖塔台 起飞
 * @Date: 2019-06-28 16:29:41
 * @LastEditTime: 2020-09-03 15:19:39
 */
#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define endl '\n'
typedef long long ll;

const int N = 1e6 + 105;
const int MOD = 1e9 + 7;

int main(){
    int n; cin >> n;
    map<ll, ll> ma;
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        ll x; cin >> x;
        ans += ma[-(x - i)];
        ma[i + x]++;
    }
    cout << ans << endl;
    // system("pause");
}