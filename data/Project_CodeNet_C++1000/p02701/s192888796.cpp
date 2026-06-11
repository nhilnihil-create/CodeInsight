#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N; cin >> N;
    int ans = 0;
    map<string,int> mp;
    rep(i,N) {
        string s; cin >> s;
        mp[s]++;
    }
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(itr->second>0) ans++;
    }
    cout << ans << endl;
}