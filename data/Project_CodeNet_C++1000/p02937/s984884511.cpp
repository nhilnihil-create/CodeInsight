#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
const int MOD = 1000000007;


int main(){
    string S, T; cin >> S >> T;

    map<char, vector<int>> position;
    rep(i,S.size()){
        position[S[i]].push_back(i);
    }

    ll ans = 0;
    int prev_index = 0;
    rep(i,T.size()){
        char t = T[i];

        if (position[t].empty()){
            cout << -1 << endl;
            return 0;
        }
        if (i == 0){
            prev_index = position[t][0];
            ans = prev_index;
        }
        else{
            int size = position[t].size();
            vector<int> c = position[t];
            int next_index;
            if (prev_index >= c[size-1]){
                next_index = c[0];
            }
            else{
                int ng = -1;
                int ok = c.size();
                while(abs(ok-ng) > 1){
                    int mid = (ok+ng)/2;
                    if (c[mid] > prev_index) ok = mid;
                    else ng = mid;
                }

                next_index = c[ok];
            }
            if (prev_index < next_index){
                ans += next_index-prev_index;
            }
            else{
                ans += next_index + (S.size() - prev_index);
            }
            prev_index = next_index;
        }

        
    }

    cout << ans+1 << endl;
}