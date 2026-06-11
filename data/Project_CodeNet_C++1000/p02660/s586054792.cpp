#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

vector<pair<int,int>> solve(ll N){
    vector<pair<int,int>> v;
    ll sqrt = pow(N, 0.5);
    for(int i = 2; i <= sqrt; i++){
        int cnt = 0;
        while(true){
            if(N % i == 0){
                cnt++;
                N /= i;
            }
            else break;
        }
        if(cnt != 0) v.push_back({i, cnt});
    }
    if(N != 1) v.push_back({N, 1});
    return v;
}

ll cal(vector<pair<int,int>> &v){
    int ans = 0;
    for(auto s:v){
        ll n = s.second;
        ll i = 1;
        while(n >= i){
            ans++;
            n -= i;
            i++;
        }
    }
    return ans;
}
int main(){
    ll N;
    cin >> N;
    auto v = solve(N);
    int ans = cal(v);
    cout << ans << endl;
}
