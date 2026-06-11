#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    const i64 INF = 1e8;
    int N;
    cin >> N;
    int P = 1 << N;
    multiset<int, greater<int>> s;
    for(int i = 0; i < P; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    vector<int> v;
    v.push_back(*s.begin());
    s.erase(s.begin());
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < (1 << k); i++) {
            auto itor = s.upper_bound(v[i]);
            if(itor == s.end()) {
                cout << "No" << endl;
                return 0;
            }
            v.push_back(*itor);
            s.erase(itor);
        }
    }
    cout << "Yes" << endl;
    return 0;
}