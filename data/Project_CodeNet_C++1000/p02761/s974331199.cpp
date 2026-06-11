// C - Guess The Number
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    rep(i, m) cin >>p[i].first >> p[i].second;
    rep(i, 1000){
        int keta = 1;
        int ni = i/10;
        vector<int> d(1, i%10);
        while(ni){
            keta++;
            d.push_back(ni%10);
            ni /= 10;
        }
        if(keta != n) continue;
        bool ok = true;
        reverse(d.begin(), d.end());
        rep(i, m){
            if(d[p[i].first-1] != p[i].second) ok = false;
        }
        if(ok){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}