#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define p_b push_back
#define pll pair < ll , ll >

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll ch  = 0;
    while(n)
    {
        n/=k;
        ch++;
    }
    cout << ch;
}
