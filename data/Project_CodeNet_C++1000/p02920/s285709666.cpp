#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    multiset<ll> s;
    Rep (i, 1<<N) {
        ll S;
        cin >> S;
        s.insert(S);
    }

    vec exist;
    auto itr = s.end();
    itr--;
    exist.push_back(*itr);
    Rep (i, N) {
        Rep (j, 1<<i) {
            itr = s.lower_bound(exist[j]);
            if (itr == s.begin()) {
                cout << "No\n";
                return 0;
            }
            itr--;
            exist.push_back(*itr);
            s.erase(itr);
        }
    }

    cout << "Yes\n";
    return 0;
}