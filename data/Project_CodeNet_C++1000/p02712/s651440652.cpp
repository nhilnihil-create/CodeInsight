#include<bits/stdc++.h>
using namespace std;
#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define ll long long
typedef pair<int, int> P;

int main(){
    ll n;
    ll res = 0;
    cin >> n;
    rep(i, n+1) {
        if(i % 15 != 0 && i % 5 != 0 && i % 3 != 0) {
            res += i;
        }
    }
    cout << res << endl;
}
