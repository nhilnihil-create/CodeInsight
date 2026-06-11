#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int r;
void input()
{
    cin>>r;
}

void solve()
{
    cout<<fixed<<setprecision(5)<<2*r*3.141592<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}