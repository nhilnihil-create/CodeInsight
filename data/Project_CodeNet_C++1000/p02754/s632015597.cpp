#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

ll N,A,B;
void input()
{
    cin>>N>>A>>B;
}

void solve()
{
    ll ans=(N/(A+B))*A+min(A,N%(A+B));
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}