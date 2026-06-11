#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a[5];
    int ans = 1;
    for(int &i: a) cin >> i;
    for(int i=0;i<5;i++) if(a[i]==0) ans = i+1;
    cout << ans << '\n';
    return 0;
}