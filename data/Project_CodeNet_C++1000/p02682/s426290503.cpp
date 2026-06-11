#include <iostream>
using namespace std;
void solve()
{   int a,b,c,k; cin >> a >> b >> c >> k;
    if(k-a<=0) cout << k;
    else
    {
        if(k-a-b<=0) cout << a;
        else cout << a-(k-a-b);
    }
}

int main()
{
    solve();
}
