#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        rep(i, n)cin >> a[i];
        int cnt = 0;
        int th = (accumulate(a.begin(), a.end(), 0)+4*m-1)/(4*m);
        rep(i, n){
                if(a[i]>=th)cnt++;
                if(cnt>=m){
                        cout << "Yes" << endl;
                        return 0;
                }
        }
        cout << "No" << endl;
        return 0;
}