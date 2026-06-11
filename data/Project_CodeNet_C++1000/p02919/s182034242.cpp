#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        int a; cin >> a; a--; 
        pos[a] = i;
    }
    multiset<int> st;
    for(int i = 0; i < 2; i++){st.insert(-1),st.insert(n);}


    ll sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        auto itr = st.lower_bound(pos[i]);
        ll l2 = *prev(itr, 2), l1 = *prev(itr, 1);
        ll r2 = *next(itr, 1), r1 = *itr;
        st.insert(pos[i]);

        ll cur = (l1 - l2) * (r1 - pos[i]);
        cur +=   (r2 - r1) * (pos[i] - l1);
        sum += cur * (i + 1);
    }
    cout << sum << endl;
}