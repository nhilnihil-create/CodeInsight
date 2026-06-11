#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    rep(i,n) {
        cin >> h[i];
    }
    
    h[0]--;
    for(int i = 1; i < n; i++) {
        if(h[i] < h[i-1]) {
            cout << "No" << endl;
            return 0;
        }
        else if(h[i] > h[i-1]) {
            h[i]--;
        }
    }
    
    cout << "Yes" << endl;
    
    
    
    return 0;
}
