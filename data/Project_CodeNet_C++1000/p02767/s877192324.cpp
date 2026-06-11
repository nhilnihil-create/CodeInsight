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

int main(){
    int N;
    ll res = INF;
    cin >> N;
    vector<int> X(N);
    for(int i = 0;i < N; i++) cin >> X[i];
    for(int i = 1;i < 101; i++){
        ll ans = 0;
        for(int j = 0; j < N; j++){
            ans += (i - X[j]) * (i - X[j]);
        }
        res= min(res, ans);
    }
    cout << res << endl;
}
