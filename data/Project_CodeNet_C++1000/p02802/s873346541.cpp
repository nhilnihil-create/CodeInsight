#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, m; cin >> n >> m;
    V<int> wa(n + 1, 0);
    V<bool> ac(n + 1, false);

    int acn = 0, wan = 0;
    for(int i = 0; i < m; i++){
        int p; cin >> p;
        string s; cin >> s;
        if(ac[p]) continue;
        if(s == "AC"){
            ac[p] = true;
            acn++;
            wan += wa[p];
        }else{
            wa[p]++;
        }
    }
    cout << acn << ' ' << wan << endl;

    return 0;
}
