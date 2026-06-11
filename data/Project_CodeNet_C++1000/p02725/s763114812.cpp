#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int M = a[0];
    for(int i = 1; i < n; i++){
        M = max(a[i] - a[i - 1], M);
    }
    M = max(k - a[n - 1] + a[0], M);

    cout << k - M << endl;
    
    return 0;
}