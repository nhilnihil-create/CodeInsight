#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i, n) for(int i = 0;i < n;i++)
const int INF = 1LL << 30;

int MOD = 1000000007;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d; cin >> a >> b >> c >> d;

    if(c-a==1) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}