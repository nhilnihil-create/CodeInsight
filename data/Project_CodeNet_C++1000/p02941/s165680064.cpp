#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    b.resize(n);
    for(auto &i : b) cin >> i;
    auto check = [](int i){
        if(a[i] == b[i]) return false;
        int s = b[(i - 1 + n) % n] + b[(i + 1) % n];
        return b[i] >= s;
    };
    deque <int> ready;
    for(int i = 0 ; i < n ; i++){
        if(check(i)) ready.push_back(i);
    }
    ll ans = 0;
    while(ready.size()){
        int i = ready.front();
        ready.pop_front();
        int diff = b[i] - a[i];
        if(diff < 0) finish(-1);
        int s = b[(i - 1 + n) % n] + b[(i + 1) % n];
        int x = diff / s;
        ans += x;
        b[i] -= x * s;
        for(auto j : {(i - 1 + n) % n, (i + 1) % n}){
            if(check(j)) ready.push_back(j);
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] != b[i]) finish(-1);
    }
    cout << ans << endl;
}
