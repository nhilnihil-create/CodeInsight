/*
ABC138-E
英小文字からなる二つの文字列s,tが与えられる。
次の条件を満たす整数i(1<=i<=10^100)が存在し、
存在する場合はそのようなiの最小値を求める。
・sを10^100個連結して得られる文字列をs'とする。
　tは、文字列s'1s'2...s'iの部分列である。
制約
1<=|s|<=10^5
1<=|t|<=10^5
方針
まず、各文字列の出現位置を記憶する。
その後、tを1文字ずつ操作し、二分探索により
前回の文字列の位置より後ろにある今回の文字列の
位置を取得し、答えに加算する。
前回の文字列の位置より後ろに今回の文字列がない場合、
今回の文字列の出現位置のうち最も手前の位置と
(文字列の終端-前回の位置)を加算したものを
答えに加える。
*/

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
                
                ll ng = -1;
                ll ok = c.size();
                
                while(abs(ok-ng)>1){
                    ll mid = (ok+ng) / 2;
                
                    if(c[mid] > prev_index) ok = mid;
                    else ng = mid;
                }

                next_index = c[ok];
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