#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, x;
    cin >> n >> x;
    
    vector<int> l(n);
    vector<int> bound(n+1,0);
    
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) bound[i] = bound[i-1] + l[i-1];
    
    int ans = upper_bound(bound.begin(),bound.end(),x) - bound.begin();
    
    cout << ans << endl;
}
