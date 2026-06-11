#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    ll a,b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    if((a+b)% 2 == 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << (a+b) / 2 << endl;
}