#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
multiset<pair<ll, ll>, greater<> > ms;
#define MAXN 200001
ll a[MAXN];
ll b[MAXN];
bool finish[MAXN];
int main() {
    int n;
    cin >> n;
    ll ret = 0;
    int fin_count = 0;
    memset(finish, false, sizeof(finish));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] == b[i]) {
            finish[i] = true;
            fin_count++;
        }
        if (!finish[i]) ms.insert(make_pair(b[i], i));
    }
    while (fin_count < n) {
        int id = (*ms.begin()).second;
        //cout << id << endl;
        int id_b, id_n;
        if (id == 0) {
            id_b = n - 1;
            id_n = 1;
        }
        else if (id == n - 1) {
            id_b = n - 2;
            id_n = 0;
        }
        else {
            id_b = id - 1;
            id_n = id + 1;
        }
        if (b[id] <= b[id_b] + b[id_n]) {
            break;
        }
        ll q = (b[id] - a[id]) / (b[id_b] + b[id_n]);
        b[id] -= q * (b[id_b] + b[id_n]);
        if (q == 0) {
            break;
        }
        else if (a[id] == b[id]) {
            fin_count++;
            ms.erase(ms.begin());
            ret+=q;
            //cout << "JJJ" << endl;
        }
        else {
            ms.erase(ms.begin());
            ms.insert(make_pair(b[id], id));
            ret+=q;
        }
    }
    if (fin_count < n) {
        cout << -1 << endl;
    }
    else {
        cout << ret << endl;
    }
    return 0;
}