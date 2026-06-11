#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, k, s; cin >> n >> k >> s;

    V<int> ans;
    for(int i = 0; i < n - k; i++){
        if(s != 1e9) ans.push_back(s + 1);
        else ans.push_back(s - 1);
    }
    while(0 < k){
        ans.push_back(s);
        k--;
    }

    sort(ALL(ans));
    for(int a : ans){
        cout << a << endl;
    }

    return 0;
}
