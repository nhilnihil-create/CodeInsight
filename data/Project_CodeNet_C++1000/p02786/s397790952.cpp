#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ll cnt_at(ll hp, int depth) {
//     if(hp > 1){
//         depth++;
//         return pow(2, depth)*cnt_at(hp / 2, depth);
//     }
//     else{
//         return pow(2, depth);
//     }
// }

ll rec(ll hp) {
    if (hp == 1) return 1;
    ll ans = rec(hp / 2) * 2 + 1;
    return ans;
}

int main() {
    ll hp;
    cin >> hp;
    // int depth = 0;
    ll ans = rec(hp);
    // while(hp > 0){
    //     ans += pow(2, depth);
    //     hp /= 2;
    //     depth++;
    // }
    cout << ans << endl;
    return 0;
}