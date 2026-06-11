#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i,n) cin >> L.at(i);
    L.push_back(INF);
    sort(L.begin(),L.end());
    int ans = 0;
    for(int i = 0; i < n;i++){
        for(int j = i+1; j < n;j++){
            int l = j;
            int r = n;
            while(l + 1 < r){
                int m = (l+r)/2;
                if(L.at(m) < L.at(i) + L.at(j)) l = m;
                else r = m;
            }
            ans += (l - j);
        }
    }
    cout << ans << endl;
}