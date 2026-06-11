#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll n,k;
void input()
{
    cin>>n>>k;
}

void solve()
{
    n%=k;
    cout<<min(n,k-n)<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}