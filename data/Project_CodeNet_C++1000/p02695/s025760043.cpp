#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
long mod = (long) 1e9 + 7;
int n, m, q, a[50], b[50], c[50], d[50], ans = 0;

int bfs(vector<int> t){
    
    if(t.size() == n){
        int sum = 0;
        rep(i,q){
            if(t[b[i]] - t[a[i]] == c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        
    } else {
        int back = 1;
        if(t.size() > 0) back = t.back();
        for(int i = back; i <= m; i++){
            t.push_back(i);
            bfs(t);
            t.pop_back();
        }
    }
    return 0;
}

int main(){
    
    cin >> n >> m >> q;
    
    rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    rep(i,q) a[i]--, b[i]--;
    
    bfs({});
    
    cout << ans << "\n";
    
    return 0;
}

