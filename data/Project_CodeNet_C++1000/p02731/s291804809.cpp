#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int L;
void input()
{
    cin>>L;
}

void solve()
{
    double a=1.0*L/3.0;
    cout<<fixed<<setprecision(10)<<a*a*a<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}