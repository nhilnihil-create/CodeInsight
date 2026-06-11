#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(q);
    vector<int> b(n, k - q);
    for(int i = 0; i < q; i++){
        cin >> a[i];
        b[a[i] - 1]++;
    }

    for(int i = 0; i < n; i++){
        if(b[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}