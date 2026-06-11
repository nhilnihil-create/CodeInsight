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

    int n; cin >> n;

    if(n%2==1){
        cout << n/2 << endl;
    } else {
        cout << n/2-1 << endl;
    }

    return 0;
}