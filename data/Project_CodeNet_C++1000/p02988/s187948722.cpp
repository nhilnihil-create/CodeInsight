#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p.at(i);
    int ans = 0;
    for(int i = 1; i < n-1;i++){
        if(p.at(i-1) > p.at(i) && p.at(i) >= p.at(i+1)){
            ans++;
            continue;
        }
        if(p.at(i+1) > p.at(i) && p.at(i) >= p.at(i-1)){
            ans++;
            continue;
        }
    }
    cout << ans << endl;
}