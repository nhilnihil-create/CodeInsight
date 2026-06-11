#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    reverse(h.begin(),h.end());
    h.push_back(-1);
    rep(i,n){
        if(h[i]<h[i+1]){
            if(h[i]==h[i+1]-1) h[i+1]--;
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}