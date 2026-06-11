#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    for (int i = 0; i < n; i++) {
        if (i == 0) h[i]--;
        else if(h[i-1] < h[i]) h[i]--;
        else if(h[i-1] == h[i]) continue;
        else if(h[i-1] > h[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}