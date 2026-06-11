#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a,b,c,k;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> k;
    if(k <= a) cout << k;
    else if(k<=b) cout << a;
    else {
        k -= (a+b);
        cout << a-k;
    }
    cout << '\n';
    return 0;
}