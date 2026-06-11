#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N;
void input()
{
    cin>>N;
}

void solve()
{
    cout<<(N+1)/2<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}