#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n;cin >> n;
    vector<int> x(n),d(n);
    ll total = 0;
    rep(i,n) {
        cin >> d[i];
        total += d[i];
    }
    total;
    for(int i = 1;i<n-1;i+=2) total -= 2*d[i];
    x[0] = total;
    for(int i = 1;i<n;i++){
        x[i] = d[i-1]*2 - x[i-1];
    }

    rep(i,n) cout << x[i] << endl;
}