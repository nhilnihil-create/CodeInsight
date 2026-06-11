#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


int main() {
    int x; cin >> x;
    multimap<int,int> m;
    for(int i = 1;i <= x;i++){
        m.insert(make_pair(i,0));
    }
    for(int i = 0;i < x-1;i++){
        int y; cin >> y;
        auto z = m.find(y);
        z->second++;
    }
    for(int i = 1;i <= x;i++){
        auto z = m.find(i);
        cout << z->second << endl;
    }
}

