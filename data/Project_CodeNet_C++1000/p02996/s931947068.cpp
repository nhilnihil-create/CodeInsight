#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    vector<P>p(n);
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        swap(a,b);
        p[i].first = a;p[i].second = b;
    }
    sort(p.begin(),p.end());
    ll sum = 0;
    bool ok = true;
    rep(i,n) {
        sum += p[i].second;
        if(sum > p[i].first) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}