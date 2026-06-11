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

int N;

vector<string> ans;

void dfs(string a, int used_count){
    if (a.size() == N){
        ans.push_back(a);
        return;
    }

    int next_count = used_count;
    rep(i,used_count+1){
        char next_char = 'a'+i;
        if (i == used_count) next_count++;
        
        dfs(a+next_char, next_count);
    }

}

int main(){
    cin >> N;

    dfs("a", 1);

    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
}