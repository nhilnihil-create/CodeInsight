#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; i<n; i++)
#define REP2(i, a, b) for(int i=a; i<b; i++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int main(){
    int N;
    cin >> N;
    vector<int> P(N+1);
    vector<int> Pinv(N+1);
    REP(i, 1, N+1) cin >> P[i];
    REP(i, 1, N+1) Pinv[P[i]] = i;

    multiset<int> st;
    st.insert(0);
    st.insert(0);
    st.insert(N+1);
    st.insert(N+1);
    st.insert(Pinv[N]);

    long long ans = 0;
    for(long long i=N-1; i>=1; i--){
        int id = Pinv[i];
        auto itr = st.lower_bound(id);
        long long r0 = *itr;
        itr++;
        long long r1 = *itr;
        itr--; itr--;
        long long l0 = *itr;
        itr--;
        long long l1 = *itr;

        ans += i*((r1-r0)*(id-l0)+(l0-l1)*(r0-id));
        st.insert(id);
    }
    cout << ans << endl;
    return 0;
}
