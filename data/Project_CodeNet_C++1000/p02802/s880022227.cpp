#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> ac(n+1), wa(n+1);
    
    rep(i,m) {
        int p;
        string s;
        cin >> p >> s;
        
        if(ac[p] == 0 && s == "AC") {
            ac[p]++;
        }
        
        if(ac[p] == 0 && s == "WA") {
            wa[p]++;
        }
    }
    
    int co, pe;
    co = pe = 0;
    for(int i = 1; i <= n; i++) {
        co += ac[i];
        if(ac[i] > 0)
            pe += wa[i];
    }
    
    cout << co << " " << pe << endl;
    
    
    return 0;
}


