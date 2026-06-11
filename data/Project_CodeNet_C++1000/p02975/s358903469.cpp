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
int N;
int a[105000];

int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    if(N % 3 != 0) {
        for(int i = 1; i <= N; i++) {
            if(a[i] != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    set<int> st;
    map<int, int> mp;
    for(int i = 1; i <= N; i++) {
        st.insert(a[i]);
        mp[a[i]]++;
    }
    if(st.size() > 3) {
        cout << "No" << endl;
        return 0;
    }
    vector<int> v;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        while(mp[*itr] > 0) {
            if(mp[*itr] % (N / 3) != 0) {
                cout << "No" << endl;
                return 0;
            }
            mp[*itr] -= N / 3;
            v.push_back(*itr);
        }
    }
    cerr << v[0] << " " << v[1] << " " << v[2] << endl;
    if((v[0] ^ v[1]) == v[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
