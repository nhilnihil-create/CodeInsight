#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    ll n, a ,b;
    cin >> n >> a >> b;
    ll dif = b - a;
    if(dif % 2 == 0) cout << dif / 2 << endl;
    else{
        ll tmp = min(a-1, n-b);
        cout << tmp + 1 + (b-a-1)/2;
    }
}