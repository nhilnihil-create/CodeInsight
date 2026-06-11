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
    int n,k;
    cin >> n >> k;
    if(n>=10)
    {
        cout << k;
    }
    else
    {
        cout << k+100*(10-n);
    }
}
