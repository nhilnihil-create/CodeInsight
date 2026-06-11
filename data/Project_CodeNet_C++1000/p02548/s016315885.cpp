/*
 * @Author: AsilenceBTF
 * @Buff: ︿(￣︶￣)︿  芜湖塔台 起飞
 * @Date: 2019-06-20 09:22:24
 * @LastEditTime: 2020-09-21 15:12:08
 */
#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define ALL(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
#define debug(x) cout << "##### " << x << endl; 
typedef long long ll;

const int N = 1e7 + 105;

// #define cin in
// #define cout out
// ifstream in("in.txt");
// ofstream out("out.txt");
int main(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n - 1; ++i){
        ans += (n - 1) / i;
    }
    cout << ans << endl;
    // system("pause");
}
