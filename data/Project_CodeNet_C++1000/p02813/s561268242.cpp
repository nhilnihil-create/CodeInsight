#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

int kai(int x) {
    int total = 1;
    for(; x > 0; x--) {
        total *= x;
    }
    
    return total;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n), q(n);
    rep(i,n) {
        cin >> p[i];
    }
    rep(i,n) {
        cin >> q[i];
    }
    
    vector<int> all(n);
    rep(i,n) {
        all[i] = i+1;
    }
    
    map<vector<int>,int> m;
    do {
        m[all] = (int)m.size();
    }while(next_permutation(all.begin(), all.end()));
    
    
    cout << abs(m[p] - m[q]) << endl;
    
    
    
    
    return 0;
}
