#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void) {
    int N; cin >> N;
    int ans = N/2;
    if(ans*2 < N) ans +=1;
    cout << ans << endl;
}