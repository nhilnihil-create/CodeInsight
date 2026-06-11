#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

void code() {
    string s;
    cin>>s;
    if(s[2]==s[3] && s[4]==s[5])
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    for(int i=0; i<t; i++) {
        code();
    }
}
