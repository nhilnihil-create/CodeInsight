#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string s, t; cin >> s >> t;

    map<char, vector<int>> cnt;
    for(int i=0; i<s.size(); i++){
        cnt[s.at(i)].push_back(i);
    }

    for(char c : t){
        if(cnt[c].empty()){
            cout << -1 << endl;
            return 0;
        }
    }

    int p = 0, q = -1;
    for(char c : t){
        const auto& v = cnt[c];
        int a = upper_bound(v.begin(), v.end(), q) - v.begin();
        if(a != v.size()){
            q = v[a];
            continue;
        }
        p++;
        q = v[0];
    }

    cout << long(p) * s.size() + q + 1 << endl;
    return 0;
}
