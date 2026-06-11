// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    vector<char> Pre(K, 'a');
    int ans = 0;
    rep(i, N){
        if(T[i] == 'r'){
            if(Pre[i % K] == 'p'){
                Pre[i % K] = 'a';
                continue;
            } else {
                Pre[i % K] = 'p';
                ans += P;
            }
        }
        if(T[i] == 's'){
            if(Pre[i % K] == 'r'){
                Pre[i % K] = 'a';
                continue;
            } else {
                Pre[i % K] = 'r';
                ans += R;
            }
        }
        if(T[i] == 'p'){
            if(Pre[i % K] == 's'){
                Pre[i % K] = 'a';
                continue;
            } else {
                Pre[i % K] = 's';
                ans += S;
            }
        }
    }

    cout << ans << endl;
}