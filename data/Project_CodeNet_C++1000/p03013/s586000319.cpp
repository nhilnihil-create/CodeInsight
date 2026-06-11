#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[m];
    set<int> st;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }
    long long p[n+1]; //i段目にたどりつくまでの移動方法をp[i]通りとする
    p[0] = 1;
    if (*st.begin() == 1) {
        p[1] = 0;
        st.erase(st.begin());
    } else {
        p[1] = 1;
    }
    for (int i=2; i<n+1; i++) {
        if (*st.begin() == i) {
            p[i] = 0;
            st.erase(st.begin());
        } else {
            p[i] = (p[i-1] + p[i-2]) % 1000000007;
        }
    }
    cout << p[n] << endl;
}