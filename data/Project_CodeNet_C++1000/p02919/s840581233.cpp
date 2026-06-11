#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, P[100000], pos[100001];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> P[i];
        pos[P[i]] = i;
    }
    multiset<int64_t> st = {-1, -1, N, N};
    int64_t ans = 0;
    for(int i=N; i>0; i--){
        st.insert(pos[i]);
        auto it = st.lower_bound(pos[i]);
        auto l1 = prev(it);
        auto l2 = prev(l1);
        auto r1 = next(it);
        auto r2 = next(r1);
        int64_t num = (*l1 - *l2) * (*r1 - pos[i]) + (pos[i] - *l1) * (*r2 - *r1);
        ans += i * num;
    }
    cout << ans << endl;
    return 0;
}
