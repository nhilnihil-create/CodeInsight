#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    cout << max(0,c - (a - b)) << endl;
    
    
    
    return 0;
}
