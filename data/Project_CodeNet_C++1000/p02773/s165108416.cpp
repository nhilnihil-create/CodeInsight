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
    int n; cin >> n;
    multimap<string,int> m;
    for(int i = 0;i < n;i++){
        string s; cin >> s;
        auto x = m.find(s);
        if(x == m.end()){
            m.insert(make_pair(s,1));
        }else{
            x->second++;
        }
    }
    int z = 0;
    for(auto x:m){
        z = max(z,x.second);
    }
    for(auto x:m){
        if(x.second == z) cout << x.first << endl;
    }
}


