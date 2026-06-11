#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cp(a);
    sort(cp.begin(),cp.end());
    int max1 = cp[n-1];
    int max2 = cp[n-2];
    rep(i,n){
        if(a[i]==max1){
            cout << max2 << endl;
        }else{
            cout << max1 << endl;
        }
    }
}