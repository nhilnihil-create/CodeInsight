// Atcoder beginner round 174 B - Distance

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll X[2000005], Y[2000005];

int main() {
    ll N, D, ans = 0;
    cin >> N >> D;
    for (int x = 0; x < N; x++)
        cin >> X[x] >> Y[x];
    for (int x = 0; x < N; x++) 
        if(X[x]*X[x] + Y[x]*Y[x] <= D*D) 
            ans++; 
    cout << ans;
    return 0;
}