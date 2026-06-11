#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> used;
    int index = 0;
    int loop_size;
    int loop_begin;
    vector<bool> checked(n, false);
    while(1){
        checked[index] = true;
        used.push_back(index);
        k--;
        index = a[index];
        if (k == 0){
            cout << index + 1 << endl;
            return 0;
        }

        if (checked[index]){
            auto itr = find(used.begin(), used.end(), index);
            loop_size = used.size() - (itr - used.begin());
            loop_begin = index;
            break;
        }
    }

    k %= (ll)loop_size;
    int res = loop_begin;
    for (int i = 0; i < k; ++i) {
        res = a[res];
    }
    cout << res + 1 << endl;
}
