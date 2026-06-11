#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n,k,q; cin >> n >> k >> q;
    vector<int> vec(n, k-q);
    rep(i, q){
        int a; cin >> a;
        a--;
        vec.at(a)++;
    }
    rep(i,n){
        if(vec.at(i) > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
