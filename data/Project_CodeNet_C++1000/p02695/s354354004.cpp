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

int main(){
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> a(q,0), b(q,0), c(q,0), d(q,0);
    
    rep(i,q){
        int aa, bb;
        cin >> aa >> bb >> c[i] >> d[i];
        aa--;
        bb--;
        a[i] = aa;
        b[i] = bb;
    }

    vector<int> l(10,1);
    
    int ans = 0;
    
    while(1){
        
        int sum = 0;
        
        rep(i,q){
            if(l[b[i]] - l[a[i]] == c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        
        int x;
        
        for(x = n - 1; x >= 0; x--){
            if(l[x] < m) break;
        }
        
        if(x <= 0) break;
        
        l[x]++;
        for(int j = x + 1; j < n; j++){
            l[j] = l[x];
        }
  
    }
    
    cout << ans << "\n";
    
    return 0;
}

