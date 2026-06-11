#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int p[100005], q[100005];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    set<int> st;
    ll l[100005], l2[100005], r[100005], r2[100005];
    for(int i = 0; i < n; i++){
        l[i] = -1;
        l2[i] = -1;
        r[i] = n;
        r2[i] = n;
    }
    for(int i = n - 1; i >= 0; i--){
        auto itr = st.lower_bound(q[i]);
        if(itr != st.end()){
            r[i] = *itr;
            if(++itr != st.end()){
                r2[i] = *itr;
            }
            itr--;
        }
        if(itr != st.begin()){
            l[i] = *--itr;
            if(itr != st.begin()){
                l2[i] = *--itr;
            }
        }
        st.insert(q[i]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (i + 1) * ((r2[i] - r[i]) * (q[i] - l[i]) + (r[i] - q[i]) * (l[i] - l2[i]));
    }
    cout << ans << endl;
}
