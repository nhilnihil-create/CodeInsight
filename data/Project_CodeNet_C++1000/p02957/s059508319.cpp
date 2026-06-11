#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a, b;
    cin >> a >> b;
    
    if((a+b)%2 == 0)
        cout << (a+b) / 2 << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    
    
    
    return 0;
}
