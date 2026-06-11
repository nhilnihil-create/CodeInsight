#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<bool>> l(n, vector<bool>(10)), r(n, vector<bool>(10));
    l[0][s[0] - '0'] = true;
    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            l[i][j] = l[i-1][j];
        }
        l[i][s[i] - '0'] = true;
    }
    r[n-1][s[n-1] - '0'] = true;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<10;j++){
            r[i][j] = r[i+1][j];
        }
        r[i][s[i] - '0'] = true;
    }

    set<int> ans;
    for(int c = 1; c < n-1;c++){
        int cc = s[c] - '0';
        for(int ll=0;ll<10;ll++){
            for(int rr=0;rr<10;rr++){
                if(l[c-1][ll] && r[c+1][rr]){
                    ans.insert(ll * 100 + cc * 10 + rr);
                } 
            }
        }
    }
    // for(auto&& x:ans)cerr << setw(3) << setfill('0') << x << endl;
    cout << ans.size() << endl;
    return 0;
}