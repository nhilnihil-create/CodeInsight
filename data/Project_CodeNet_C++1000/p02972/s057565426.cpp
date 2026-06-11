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

    vector<int> counter(N+1,0);
    vector<int> ans;
    for(int i = N-1; i >= 0; i--){
        int count = 0;
        int now = i+1;
        while (now <= N){
            count += counter[now];
            now += i+1;
        }
       
        if (count%2 != a[i]){
            counter[i+1]++;
            ans.push_back(i+1);
        }
    }
/*
    rep(i,counter.size()){
        cout << i << " " << counter[i] << endl;
    }
*/
    int size = ans.size();
    cout << size << endl;
    if (size > 0){
        rep(i,size){
            cout << ans[i] << endl;
        }
    }
}