#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> vec(n);
    rep(i,n){
        cin >> a.at(i);
        vec.at(a.at(i)-1) = i+1;
    }
    rep(i, n){
        cout << vec.at(i) << ' ';
    }
    return 0;
}
