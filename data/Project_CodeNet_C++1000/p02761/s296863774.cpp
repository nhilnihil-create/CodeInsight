#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, m; cin >> n >> m;
    V<int> s(m), c(m);
    for(int i = 0; i < m; i++) cin >> s[i] >> c[i];

    for(int i = 0; i < 1000; i++){
        string tmp = to_string(i);
        if((int)tmp.size() != n) continue;
        bool flag = true;
        for(int j = 0; j < m; j++){
            if(tmp[s[j] - 1] - '0' != c[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
