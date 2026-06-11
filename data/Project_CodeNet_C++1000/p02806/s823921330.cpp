#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <string>

typedef long long ll;
using namespace std;
const int mod = 1000000007;

int main() {

    int N; cin >> N;
    vector< pair<string, int> > v(N);
    string s; int t;
    for (int i = 0; i < N; i++) {
        cin >> s >> t;
        v[i] = make_pair(s, t);
    }
    cin >> s;
    int ans = 0;
    int isfind = false;
    for (int i = 0; i < N; i++) {
        if (isfind)
            ans += v[i].second;
        else 
            if (v[i].first == s)
                isfind = true;
    }
    cout << ans << '\n';


}
