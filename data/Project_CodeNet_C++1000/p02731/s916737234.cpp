#include <bits/stdc++.h>
using namespace std;

void solve(long long L){
    double element = (double)L / 3;
    double ans = element * element * element;
    cout << fixed << setprecision(12) << ans << endl;
    return;
}

int main(){
    long long L;
    scanf("%lld",&L);
    solve(L);
    return 0;
}
