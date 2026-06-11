#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

bool check(vector<int> p, int x){
    rep(i, p.size()){
        if(p[i]==x)return false;
    }
    return true;
}

int main(){
    int x, n;
    cin >> x >> n;
    vector<int> p(n, 0);
    rep(i, n)cin >> p[i];
    
    sort(p.begin(), p.end());
    
    int ans = 10000;
    rep(i, 100){
        if(check(p, x+i)){
            ans = x+i;
        }
        if(check(p, x-i)){
            ans = (x-i<ans)? (x-i) : ans;
        }
        
        if(ans<10000)break;
    }
    
    cout << ans << endl;
    
}