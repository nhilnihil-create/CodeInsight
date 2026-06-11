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
    if(a <= 9 && b <= 9)
        cout << a * b;
    else
        cout << -1;
    return 0;
}
