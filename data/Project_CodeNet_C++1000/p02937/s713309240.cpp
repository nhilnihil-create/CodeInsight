#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int maxv = 100005;




int main(){
    string s, t;
    map<char, vector<int>> counter;
    cin >> s >> t;

    rep(i,s.size()){
        int index = i+1;
        // 各文字毎の出現位置を格納
        counter[s[i]].push_back(index);
    }

    ll ans = 0;
    int prev_index;
    // tの文字数分繰り返す
    rep(i, t.size()){
        char ch = t[i];
        // Sに登場しなかった場合は終了
        if (counter[ch].empty()){
            cout << -1 << endl;
            return 0;
        }
        if (i == 0) {
            prev_index = counter[ch][0];
            ans = prev_index;
            continue;
        }
        else{
            int size = counter[ch].size();
            vector<int> c = counter[ch];
            int next_index;
            if (prev_index >= c[size-1]){
                next_index = c[0];
            }
            else{
                int c_index = upper_bound(c.begin(), c.end(), prev_index) - c.begin();
                next_index = c[c_index];
            }

           if (prev_index < next_index){
                ans += next_index - prev_index;
            }else{
                ans += next_index + (s.size() - prev_index);
            }
            prev_index = next_index;
        }
    }
    cout << ans << endl;
}