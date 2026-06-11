#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n-1);
    rep(i,n){
        int a;
        cin >> a;
        a--;
        A.at(i) = a;
    }
    rep(i,n) cin >> B.at(i);
    rep(i,n-1) cin >> C.at(i);
    int ans = 0;
    rep(i,n){
        ans += B.at(A.at(i));
        if(i == n-1 || A.at(i) == n-1) continue;
        if(A.at(i) + 1 == A.at(i+1)) ans += C.at(A.at(i));
    }
    cout << ans << endl;
}