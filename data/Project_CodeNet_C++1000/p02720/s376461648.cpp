#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll k;
    cin >> k;
    queue<ll> que;
    rep(i, 1, 10) que.push(i);
    ll cnt = 0;
    while(true){
        cnt++;
        auto q = que.front();
        que.pop();
        // cerr << cnt << ": " << q << endl;
        if(cnt == k){
            cout << q << endl;
            break;
        }
        ll last = q % 10;
        if(cnt + que.size() > k) continue;
        if(last != 0) que.push(q * 10 + last - 1);
        que.push(q * 10 + last);
        if(last != 9) que.push(q * 10 + last + 1);
    }
    return 0;
}