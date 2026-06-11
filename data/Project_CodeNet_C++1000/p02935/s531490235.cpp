#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin >> n;
    vector<double> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    int ans=0;
    for (int i = 1; i < n ;i++)
        v[i] = (v[i - 1] + v[i]) / 2;
    cout<<v[n-1]<<endl;
}