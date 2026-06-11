#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int GCD(int a, int b)
{
    if(b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll a, ll b){
    ll g = a * b;
    ll gg = GCD(a, b);
    return g/gg;
}
int main()
{
    Hello
    ll a, b;
    cin >> a >> b;
    cout << lcm(a, b);
    return 0;
}