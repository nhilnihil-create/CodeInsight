#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int n; cin >> n;
    vector<int> vec(n-1);
    rep(i, n-1) cin >> vec.at(i);
    vector<int> vec_c(n);
    vec_c.at(0) = vec.at(0);
    vec_c.at(n-1) = vec.at(n-2);
    for(int i = 1; i < n-1; i++){
        vec_c.at(i) = min(vec.at(i), vec.at(i-1));
    }
    int sum = accumulate(vec_c.begin(), vec_c.end(), 0);
    cout << sum << endl;
    return 0;
}
