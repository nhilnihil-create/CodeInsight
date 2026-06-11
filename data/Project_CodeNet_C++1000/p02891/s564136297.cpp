#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

ll func(string s){
    int n = s.size();
    ll sum = 0;
    for(int i=0,j=0; i<n; i=j){
        while(s[i]==s[j])j++;
        sum += (j-i)/2;
    }
    return sum;
}
int main() {
    string s;
    cin >> s;
    set<char>st;
    ll k;
    cin >> k;
    int m = s.size();
    rep(i, 0, m){
        st.insert(s[i]);
    }
    ll a = func(s);
    ll b = func(s+s);
    if(st.size()==1)cout << (ll)m*k/2 << endl;
    else cout << a+(b-a)*(k-1) << endl;
}