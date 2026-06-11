#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n;
    cin >> n;
    set<string> st;
    for (int (i) = 0; (i) < n; ++(i)) {
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << st.size();
    return 0;
}