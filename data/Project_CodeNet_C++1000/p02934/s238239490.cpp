#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#include<bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n; cin >> n;
    vector<double> a(n);
    double a_times = 1.0;
    rep(i, n){
        cin >> a[i];
        a_times *= a[i];
    }

    double a_sum=0.0;
    rep(j, n){
        a_sum += a_times/a[j];
    }
    cout << a_times/a_sum << endl;
}