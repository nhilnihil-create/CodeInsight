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
    int n;
    cin>>n;
    int ans=0;
    vector<int> A(n);
    for(int i=0; i<n; i++) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    vector<int> d(1000005);
    vector<int> cnt(1000005);
    for(int i=0; i<n; i++) {
        cnt[A[i]]++;
    }
    if(A[0]==1) {
        if(cnt[1]==1)
            cout << "1\n";
        else
            cout << "0\n";
        return;
    }
    int m = *max_element(A.begin(), A.end());
    for(int i=0; i<n; i++) {
        for(int j=2*A[i]; j<=m; j+=A[i]) {
            d[j]++;
        }
    }

    for(int i=0; i<n; i++) {
        if(d[A[i]]==0 && cnt[A[i]]==1)
            ans++;
    }


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
