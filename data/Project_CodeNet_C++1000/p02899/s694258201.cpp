#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) {
        int a;
        cin >> a;
        s[a-1] = i+1;
    }
    rep(i,n) cout << s[i] << endl;
    return 0;
}