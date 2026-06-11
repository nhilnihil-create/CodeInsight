#include <bits/stdc++.h>
#include <string>
//#include <queue>
using namespace std;
#define ll long long
#define ld long double


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    if (k==1) cout << 0 << endl; else
    cout << n-k << endl;
    return(0);
}
