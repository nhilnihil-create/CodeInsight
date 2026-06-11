#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> d(n,0);
    rep(i, n-1) {
        int ai;
        cin >> ai;
        d[ai-1]++;
    }
    
    rep(i, n)
        cout << d[i] << endl;
    
    return 0;
}
