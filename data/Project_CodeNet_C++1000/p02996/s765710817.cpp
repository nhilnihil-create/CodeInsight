#include <bits/stdc++.h>
#include <math.h>
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

using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    int N; cin >> N;
    vector<pair<int, int>> AB;
    rep(i,N){
        int a,b;
        cin >> a >> b;
        AB.emplace_back(a,b);
    }

    sort(AB.begin(), AB.end(), comp);

    int time = 0;
    rep(i,N){
        time += AB[i].first;
        if (time > AB[i].second){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
}

