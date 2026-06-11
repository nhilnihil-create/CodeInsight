#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

/*
考察
- 無限回の場合は簡単に場合分けできる
- それ以外のケースはシミュレーションをしたくなるが，それはTLEっぽい
- aとbが最後に会う時間を求めれば良い気がする -> 2分探索?
- 分からん！解説を見る
*/

int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll p = a1 * t1 - b1 * t1;
    ll q = a2 * t2 - b2 * t2;
    if(p > 0){
        p = -p;
        q = -q;
    }
    if(p + q == 0){
        cout << "infinity" << endl;
    }else if(p + q < 0){
        cout << 0 << endl;
    }else{
        ll s = (-p) / (p+q);
        ll t = (-p) % (p+q);
        if(t == 0) cout << 2 * s << endl;
        else cout << 2 * s + 1 << endl;
    }
    return 0;
}