//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N; cin >> N;
    map<string,int> mp;
    set<string> ans;
    queue<string> que;
    que.push("a");

    while(1) {
        string S = que.front();
        que.pop();
        if(S.size() > N) break;
        if(S.size() == N) ans.insert(S);
        for(int i = 0; i < S.size(); i++) {
            string ret = S + S[i];
            string res = S + (char)((int)S[i]+1);
            if(!mp.count(ret)) {
                mp[ret] = 1;
                que.push(ret);
            }
            if(!mp.count(res)) {
                mp[res] = 1;
                que.push(res);
            }
        }
    }

    for(auto s:ans) cout << s << endl;
}
