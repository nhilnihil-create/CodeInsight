#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

vector<vector<int>> r;
vector<int> cnt;

void search(int i, int p) {
    rep(j,r[i].size()) {
        if(r[i][j] != p) {
            cnt[r[i][j]] += cnt[i];
            search(r[i][j],i);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    r.resize(n+1);
    cnt.resize(n+1);
    
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        
        r[a].push_back(b);
        r[b].push_back(a);
    }
    
    rep(i,q) {
        int p, x;
        cin >> p >> x;
        
        cnt[p] += x;
    }
    
    search(1,0);
    
    for(int i = 1; i <= n; i++)
        cout << cnt[i] << endl;
    
    
    return 0;
}
