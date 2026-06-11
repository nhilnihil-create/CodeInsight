#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

ll a,b,c,k;
void input()
{
    cin>>a>>b>>c>>k;
}

void solve()
{
    if(k<=a) cout<<k<<endl;
    else if(k<=a+b) cout<<a<<endl;
    else cout<<a-(k-a-b)<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}