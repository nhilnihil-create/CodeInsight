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
    
    int mx1, mx2, n1, n2;
    mx1 = mx2 = 0;
    n1 = n2 = 0;
    rep(i,n) {
        int a;
        cin >> a;
        
        if(a > mx1) {
            mx2 = mx1;
            n2 = n1;
            mx1 = a;
            n1 = i;
        }
        else if(a > mx2) {
            mx2 = a;
            n2 = i;
        }
    }
    
    rep(i,n) {
        if(i == n1)
            cout << mx2 << endl;
        else
            cout << mx1 << endl;
    }
    
    
    return 0;
}


