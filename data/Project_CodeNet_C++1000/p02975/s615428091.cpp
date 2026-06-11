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
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    map<int,int> counter;
    bool is_all_zero = true;
    
    rep(i,N){
        counter[a[i]]++;
        if (a[i] != 0) is_all_zero = false;
    }

    bool isOK = false;

    if (is_all_zero) isOK = true;

    if(N%3 == 0){
    
        int kind_count = counter.size();
        if (kind_count == 2){
            for (auto c : counter){
                if (c.first == 0){
                    if (c.second == N/3){
                        isOK = true;
                    }
                }
            }
        }
        else if (kind_count == 3){
            int xor_val = 0;
            bool countOK = true;
            for (auto c : counter){
                if (c.second != N/3){
                    countOK = false;
                }
                xor_val ^= c.first;
            }
            if (xor_val == 0 && countOK){
                isOK = true;
            }

        }
    }

    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;

}