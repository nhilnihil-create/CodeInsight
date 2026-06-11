#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    multiset<int> rest;
    cin >> N;
    for(int i = 1; i <= pow(2, N); i++) {
        int s;
        cin >> s;
        rest.insert(s);
    }
    auto itr = rest.end();
    itr--;
    multiset<int> exist;
    exist.insert(*itr);
    rest.erase(itr);
    for(int day = 1; day <= N; day++) {
        multiset<int> NEW;
        for(auto itr = exist.begin(); itr != exist.end(); itr++) {
            auto itr2 = rest.lower_bound(*itr);
            if(itr2 == rest.begin()) {
                cout << "No" << endl;
                return 0;
            }
            itr2--;
            NEW.insert(*itr2);
            rest.erase(itr2);
        }
        for(auto itr = NEW.begin(); itr != NEW.end(); itr++) {
            exist.insert(*itr);
        }
    }
    cout << "Yes" << endl;
    return 0;
}
