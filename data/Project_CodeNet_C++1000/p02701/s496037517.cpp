#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    set<string> st;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << st.size() << endl;
    return 0;
}