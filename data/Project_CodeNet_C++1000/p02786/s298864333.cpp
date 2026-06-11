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

int main() {
    ll hp;
    cin >> hp;
    int depth = 0;
    ll ans = 0;
    while(hp > 0){
        ans += pow(2, depth);
        hp /= 2;
        depth++;
    }
    cout << ans << endl;
    return 0;
}