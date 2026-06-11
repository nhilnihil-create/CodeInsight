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
    int N; cin >> N;
    string S; cin >> S;

    int ans = 0;
    for (int i = 0; i <= 999; i++){
        stringstream ss;
        ss << setfill('0') << setw(3) << i;
        string tmp = ss.str();
        int index = 0;
        for (int j = 0; j < N; j++){
            if (tmp[index] == S[j]){
                index++;
            }
            if (index == 3){
                ans++;
                break;
            }
        }
        
    }

    cout << ans << endl;
}