#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    stack<char> st;
    st.push(S[0]);
    for (ll i=1; i<N; i++) {
        if (st.top()!=S[i]) {
            st.push(S[i]);
        }
    }
    cout << st.size() << endl;
}