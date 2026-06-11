#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll k; cin >> k;
    queue<ll> que;
    rep(i, 9) que.push(i+1);
    ll cnt = 0, x = 0;
    while(cnt != k){
        x = que.front(); que.pop();
        if(x%10 != 0) que.push(10*x + x%10 - 1);
        que.push(10*x + x%10);
        if(x%10 != 9) que.push(10*x + x%10 + 1);
        cnt++;
    }
    cout << x << endl;
    return 0;
}