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
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007  

int main(){
    ll N;
    ll ans = 0;
    cin >> N;
    for(int i = 1; i < N; i++){
        ans += i * (N - i + 1);
        ll u, v;
        cin >> u >> v;
        ll m = min(u, v);
        ll M = max(u, v);
        ans -= m * (N - M + 1);
    }
    ans += N;
    cout << ans << endl;
}
