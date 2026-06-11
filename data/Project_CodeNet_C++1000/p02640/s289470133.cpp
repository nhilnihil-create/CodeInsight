#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x,y; cin >> x >> y;
    int a = 2*x;
    if(y < 2*x || y > 4*x || (y-a)%2==1) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}