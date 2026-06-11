#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n; cin >> n;
    vector<vector<pii>> f(n);
    rep(i, n){
        int a; cin >> a;
        rep(j ,a){
            pii p; cin >> p.first >> p.second;
            p.first--;
            f.at(i).push_back(make_pair(p.first, p.second));
        }
    }
    int count = 0;
    for(int bit = 0; bit < (1 << n);bit++){
        vector<bool> h(n);
        bool flag = true;
        int temp = 0;
        for(int i = 0; i < n; i++){
            if(bit >> i & 1) h.at(i) = 1;
        }
        for(int j = 0; j < n; j++){
            if(h.at(j) == 1){
                for(int k = 0; k < f.at(j).size(); k++){
                    if(f.at(j).at(k).second != h.at(f.at(j).at(k).first)) flag = false;
                }
            }
        }
        if(flag) rep(x, n){
            temp += h.at(x);
        }
        count = max(count, temp);
    }
    cout << count << endl;
    return 0;
}
