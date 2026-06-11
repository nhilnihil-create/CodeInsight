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
    int k,n;
    cin>>k>>n;
    int ans=0;
    vector<int> A(n);
    for(int i=0; i<n; i++) {
        cin>>A[i];
    }
    vector<int> dist;
    for(int i=1; i<n; i++) {
        dist.push_back(A[i]-A[i-1]);
    }
    dist.push_back(k-A.back()+A[0]);
    ans = accumulate(dist.begin(), dist.end(), 0);
    ans -= *max_element(dist.begin(), dist.end());

    cout << ans << "\n";
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    for(int i=0; i<t; i++) {
        code();
    }
}
