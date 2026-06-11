/*
* @Author: AsilenceBTF
* @Buff: ︿(￣︶￣)︿  芜湖塔台 起飞
* @Date: 2019-06-20 09:22:24
 * @LastEditTime: 2020-09-16 17:00:32
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

ll f[3050];
int main(){
    int n;
    cin >> n;
    for(int i = 3; i <= n; ++i){
        f[i] = 1;
        for(int j = 3; j <= n; ++j){
            if(i - j < 3) break;
            f[i] += f[j];
            f[i] %= MOD;
        }
    }
    cout << f[n] << endl; 
}