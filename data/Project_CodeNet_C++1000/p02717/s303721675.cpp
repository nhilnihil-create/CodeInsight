#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int x,y,z;
void input()
{
    cin>>x>>y>>z;
}

void solve()
{
    cout<<z<<" "<<x<<" "<<y<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}