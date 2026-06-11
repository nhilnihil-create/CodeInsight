#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, d;
    cin >> n >> d;
    
    int r = d * 2 + 1;
    
    cout << (n+r-1) / r << endl;
    
    
    return 0;
}


