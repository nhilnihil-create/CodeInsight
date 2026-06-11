#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// awal 10000 H => 
// Spell 1 : bisa mengurangi 1 H
// Spell 2 : bisa mengurangi 2 H
// dp(1, 10000) => dp(2, 9999) => dp(3, 9997)
             // => dp(2, 9998)
             // => dp(2, 9997) => dp(3, 9997)
             // => ...
             // => dp(2, 2)
             // => dp(2, 1)
             // => dp(2, 0)
            
// dp(1, 10000) => dp(1, 9999)
             // => dp(2, 10000)

// LL dp(LL pos, LL h){

//     // Cara 1 => O(N) dan lambat
//     // Milih di posisi ini, dengan health sekian, lu bisa ngambil berapa
//     // lu pasti lanjut
//     for(int i = 1;i <= n;i++){
//         ret = max(ret, dp(pos+1, h-a[pos]*i));
//         // Bercabang n kali
//     }

//     // Cara 2 => Optimized
//     // Milih di posisi ini, dengan 
//     // Bercabang 2 kali
//     max(dp(pos, h-a[pos]), dp(pos+1, h));
// }

LL ans = LLONG_MAX;
LL memo[10005];

int main(){
    LL n,h;
    cin >> h >> n;
    memset(memo,63,sizeof(memo));
    memo[0] = 0;
    // Profit maximum dengan cost = 0, 0
    // Profit maximum dengan cost = 1, -1 => belum ada kemungkinan yang
    //                                      membuat kita bisa mengambil total cost 1
    for(int i = 1;i <= n;i++){
        LL a, b; cin >> a >> b;
        for(int j = 0;j <= h;j++){
            if(memo[j] != LLONG_MAX){
                if(j+a >= h){
                    // Ga perlu distore
                    ans = min(ans, memo[j]+b);
                }else{
                    memo[j+a] = min(memo[j+a], memo[j]+b);
                }
            }
        }
    }
    // (<condition> ? <if true> : <if false>)
    // (a > b ? a : b)
    cout << ans << endl;
}