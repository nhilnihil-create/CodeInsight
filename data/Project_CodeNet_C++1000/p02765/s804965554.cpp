#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,r;
    cin >> n >> r;
    if(n < 10) cout << r + 100 * (10 - n) << endl;
    else cout << r << endl;
    
}