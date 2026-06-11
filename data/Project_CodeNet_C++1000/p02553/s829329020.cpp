/*
* @Author: AsilenceBTF
* @Buff: ︿(￣︶￣)︿  芜湖塔台 起飞
* @Date: 2019-06-20 09:22:24
* @LastEditTime: 2020-09-16 16:23:36
*/

#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define debug(x) cout << "##### " << x << endl; 
typedef long long ll;

// #define cin in
// #define cout out
// ifstream in("in.txt");
// ofstream out("out.txt");

const int N = 2e5 + 105;
int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = a * c;
    ans = max(ans, a * d);
    ans = max(ans, b * c);
    ans = max(ans, b * d);
    cout << ans << endl;
}