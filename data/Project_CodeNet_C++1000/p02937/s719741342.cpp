#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    string s, t;
    cin >> s >> t;

    map<char, vector<int>> m;
    for(int i=0; i<s.length(); i++){
        m[s[i]].push_back(i);
    }

    for(int i=0; i<t.length(); i++){
        if(m[t[i]].empty()){
            cout << -1 << endl;
            return 0;
        }
    }

    int tid = 0;
    int sid = 0;
    ll ans = 1;
    while(tid != t.length()){
        // cout << sid << " " << tid << endl;
        auto it = lower_bound(m[t[tid]].begin(), m[t[tid]].end(), sid);
        if(it == m[t[tid]].end()){
            ans = ans + s.length();
            sid = 0;
            it = lower_bound(m[t[tid]].begin(), m[t[tid]].end(), sid);
        }
        sid = *it + 1;
        tid++;
    }

    cout << ans + sid-1 << endl;

    return 0;
}
