#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> A(n+1);
    vector<int64_t> B(n);
    rep(i,n+1){
        cin >> A.at(i);
    }
    rep(i,n){
        cin >> B.at(i);
    }
    int64_t prev,ans;
    ans = 0;
    if (A.at(0) <= B.at(0)){
        ans += A.at(0);
        prev = B.at(0)-A.at(0);
    }
    else{
        ans += B.at(0);
        prev = 0;
    }
    for (int i=1; i<n; i++){
        if (A.at(i) < prev){
                ans += A.at(i);
                prev = B.at(i);
            }
        else{
            ans += prev;
            A.at(i) -= prev;
            if (A.at(i) <= B.at(i)){
                ans += A.at(i);
                prev = B.at(i)-A.at(i);
            }
            else{
                ans += B.at(i);
                prev = 0;
            }
        }
    }
    if (prev){
        ans += min(prev,A.at(n));
    }
    cout << ans << endl;
}