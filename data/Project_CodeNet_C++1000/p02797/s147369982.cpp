#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    vector<int > a;
    rep(i,k) a.push_back(s);
    if(k < n) {
        if(s==1e9) rep(i,n-k) {
            a.push_back(1);
        }
        else{
            rep(i,n-k) a.push_back(s+1);
        }
    }
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
    return 0;
}