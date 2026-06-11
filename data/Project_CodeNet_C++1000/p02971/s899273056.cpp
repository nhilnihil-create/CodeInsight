#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n, max = 0, idx;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i] > max){
            max = a[i];
            idx = i;
        }
    }
    sort(a.begin(), a.end());
    rep(i,n){
        if(i != idx) cout << max << endl;
        else cout << a[n-2] << endl;
    }
}