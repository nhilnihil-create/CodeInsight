#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){cin >> a[i];}
    int s = 0;
    for(int i=0; i<n; ++i){s ^= a[i];}
    for(int i=0; i<n; ++i){a[i] ^= s;}
    for(int i=0; i<n; ++i){cout << a[i] << endl;}
    return 0;
}