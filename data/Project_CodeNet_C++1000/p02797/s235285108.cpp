#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {
    ll n,s,k; cin >> n >> k >> s;
    ll p = 0;
    ll c = s/k;
    ll d = s-c*(k-1);

    rep(i,n){
        if(p < k){
            cout << s << " ";
            p ++;
        }
        else {
            if(s != 1) cout << s-1 << " ";
            else cout << s+1 << " ";
        }
    }

    return 0;
}