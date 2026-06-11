#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {

int n, i, p, dist, ans = INT_MAX;
cin >> n;
int x[n];
for(i=0; i<n; i++) cin >> x[i];
for(p=1; p<=100; p++){
    dist = 0;
    for(i=0; i<n; i++){
        dist += (p-x[i])*(p-x[i]);
    }
    ans = min(ans, dist);
}
cout << ans;
}
