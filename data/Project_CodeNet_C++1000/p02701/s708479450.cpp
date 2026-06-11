#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    set<string> st;
    while(n--){
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << st.size();


    return 0;
}
