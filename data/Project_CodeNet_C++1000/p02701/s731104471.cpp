#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    ll n;
    cin >> n;
    set<string> st;
    string s;
    for(ll i=0;i<n;i++)
    {
        cin >> s;
        st.insert(s);
    }
    cout << st.size() << endl;
    return 0;
}
