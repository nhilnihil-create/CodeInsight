#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, e=0; double p, sum=0; cin >> n; vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) sum += x[i];
    p = nearbyint(sum/n);
    for(int i=0;i<n;i++) e += pow(abs(x[i]-p), 2);
    cout << e << endl;
    return 0;
}

