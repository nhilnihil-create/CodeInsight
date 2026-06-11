#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    int ans = 0;
    rep(i,n) cin >> d.at(i);
    for(int i = 0; i < n;i++){
        for(int j = i+1;j < n;j++){
            ans += d.at(i) * d.at(j);
        }
    }
    cout << ans << endl;
}