#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n;
string s;
stack<char> st;
int main() {
    DAU
    cin >> n >> s;
    for (const char& c : s) {
        while (!st.empty() && st.top() == c)
            st.pop();
        st.emplace(c);
    }
    cout << st.size();
    PLEC
}
