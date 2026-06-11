#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    float ans = 0.0, A;
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A;
        ans += 1.0/A;
    }
    ans = 1.0/ans;
    cout << setprecision(16) << ans << endl;
    return 0;
}
