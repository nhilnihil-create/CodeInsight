#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<numeric>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

ll DENOM = 1000000000LL + 7LL;

using namespace std;

ll n, m, k;
ll h, w;


int main(){
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    vector<bool> cnd(t.size(), false);
    map<char, ll> sc;
    sc['s'] = r;
    sc['p'] = s;
    sc['r'] = p;
    ll score = 0;
    for(int i=0; i<t.size();++i){
        if(i <k){
            score += sc[t[i]];
            cnd[i] = true;
            continue;
        }
        if(cnd[i-k] && (t[i-k] == t[i])) continue;
        score += sc[t[i]];
        cnd[i] = true;
    }
    cout << score << endl;

    return 0;
}