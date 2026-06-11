#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n-1){
        int x; cin >> x;
        v.at(--x)++;
    }
    rep(i, n) cout << v.at(i) << endl;
    return 0;
}
