/*
* @Author: AsilenceBTF
* @Buff: ︿(￣︶￣)︿  芜湖塔台 起飞
* @Date: 2019-06-20 09:22:24
 * @LastEditTime: 2020-09-16 17:12:50
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

const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<ll> v, w;
    for(int i = 1; i <= n; ++i){
        ll x, y; cin >> x >> y;
        v.push_back(x + y);
        w.push_back(x - y);
    } 
    sort(ALL(v));
    sort(ALL(w));
    cout << max(v.back() - v[0], w.back() - w[0]) << endl;
}