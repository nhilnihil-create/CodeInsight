#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h, w; cin >> h >> w;

    if(h == 1 || w == 1){
        cout << 1 << endl;
    }
    else if(h % 2 == 1 && w % 2 == 1){
        cout << (h * w + 1) / 2 << endl;
    }
    else{
        cout << (h * w) / 2 << endl;
    }

    return 0;
}