#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e], pre[e];

//beginner 1999 129

int n;

int main()
{
     cin >> n;
     for(int i=1; i<=n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
     }
     ll minn = 1e9;
     for(int i=1; i<=n; i++){
         minn = min(minn, abs(pre[i] - pre[n] + pre[i]));
     }
     cout << minn;
}
