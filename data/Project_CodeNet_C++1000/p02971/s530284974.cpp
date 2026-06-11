#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int n; 
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ma, ma2;
    vector<int> sa(n);
    rep(i, n) sa[i] = a[i];
    sort(sa.begin(), sa.end());

    ma = sa[n-1];
    ma2 = sa[n -2];

    rep(i, n) {
        if(a[i] == ma) cout << ma2 << endl;
        else cout << ma << endl;
    }

    return 0;
}

