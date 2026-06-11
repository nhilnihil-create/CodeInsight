// C - management
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n-1);
    vector<int> b(n, 0);
    rep(i, n-1){
        cin >> a[i];
        b[a[i]-1]++;
    }
    rep(i, n) cout << b[i] << endl;
    return 0;
}