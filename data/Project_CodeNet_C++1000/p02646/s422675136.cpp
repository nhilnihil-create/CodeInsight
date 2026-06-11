#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int A,V,B,W,T; cin >> A>>V>>B>>W>>T;

    bool ans = false;
    if(V <= W) {

    }else{
        double t = (double)abs(A-B)/(V-W);
        if(t <= T) ans = true;
    }
    
    cout << (ans?"YES":"NO") << endl;
    return 0;
}
