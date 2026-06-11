#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n,0);
    rep(i,n) cin >> a.at(i);
    for(int i = n; i >= 1;i--){
        int x = a.at(i-1);
        ll now = 0;
        for(int j = i;j <= n;j+=i) now += b.at(j-1);
        if(a.at(i-1) % 2 != now % 2) b.at(i-1)++;
    }
    ll total = 0;
    rep(i,n) total+=b.at(i);
    cout << total << endl;
    rep(i,n) if(b.at(i) > 0) cout << (i+1) << endl;
}