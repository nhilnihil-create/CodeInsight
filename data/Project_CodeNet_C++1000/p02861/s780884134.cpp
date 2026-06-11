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
    vector<int> x(N), y(N);
    rep(i,N) cin >> x[i] >> y[i];

    vector<int> towns;
    rep(i,N){
        towns.push_back(i);
    }

    vector<double> ans;
    do{
        double tmp = 0;
        for (int i = 0; i < N-1; i++){
            int X = x[towns[i]];
            int Y = y[towns[i]];
            int X2 = x[towns[i+1]];
            int Y2 = y[towns[i+1]];

            tmp += sqrt((X-X2)*(X-X2)+(Y-Y2)*(Y-Y2));
        }
        ans.push_back(tmp);
    }while(next_permutation(towns.begin(),towns.end()));

    double sum = 0;
    rep(i,ans.size()){
        sum += ans[i];
    }

    cout << fixed << setprecision(15);
    cout << sum/ans.size() << endl;
}