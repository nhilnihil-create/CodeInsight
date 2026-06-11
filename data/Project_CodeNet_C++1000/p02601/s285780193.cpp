#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main()
{
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT

    ll r, g, b, k;
    cin >> r >> g >> b >> k;
    ll tot = 0;
    while(g<=r)
        g *= 2, tot++;
    while(b<=g)
        b *= 2, tot++;
    if(tot <= k) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
    ///MUST READ THE POINTS BELOW BEFORE SUBMIT
}
/**
    1. LOOK SPECIAL CASE N = 1.
    2. LOOK FOR OVERFLOW.
    3. LOOK FOR OUT OF BOUNDS.
**/
