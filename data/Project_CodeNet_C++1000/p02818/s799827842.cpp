#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int N = 2e3 + 5, M = 2e5;
int main()
{
    Hello
    ll a, b, k;
    cin >> a >> b >> k;
    ll ansA = a, ansB = b;
    if(k >= a){
        ansA = 0;
        ansB = max(1ll*0, b - (k - a));
    }
    else
        ansA -= k;
    cout << ansA << " " << ansB;
    return 0;
}