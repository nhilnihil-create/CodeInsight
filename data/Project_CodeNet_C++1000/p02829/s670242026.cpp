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
    if(a != 1 && b != 1)
        cout << 1;
    else if(a != 2 && b != 2)
        cout << 2;
    else
        cout << 3;
    return 0;
}