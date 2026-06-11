#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a,b; cin >> a >> b;
    if(b>=a) cout << "unsafe\n";
    else cout << "safe\n";
    return 0;
}