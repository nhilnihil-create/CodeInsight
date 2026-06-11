#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    vector<double> b(n);
    rep(i, n) b[i] = (double)1 / a[i];
    double k=0;
    rep(i, n) k += b[i];
    cout << 1 / k << endl;
}