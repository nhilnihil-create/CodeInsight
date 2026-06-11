#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    double ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        double a;
        cin >> a;
        ans += (1.0/a);
    }
    cout << fixed << setprecision(5) << (1.0/ans);
    return 0;
}
