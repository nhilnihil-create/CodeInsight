#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int k, x;
    cin >> k >> x;
    
    k--;
    
    for(int i = x - k; i < x + k; i++) {
        cout << i << " ";
    }
    cout << x + k << endl;
    
    
    
    return 0;
}


