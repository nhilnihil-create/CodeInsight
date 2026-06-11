#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int a, b;
    cin >> a >> b;
    if((a + b) % 2) cout << "IMPOSSIBLE";
    else cout << (a + b)/2;
    return 0;
}
