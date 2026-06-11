#include<iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int main()
{
    ll n, x=1, y=1, z=1;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        x*=10,y*=9,z*=8;
        x%=MOD,y%=MOD,z%=MOD;
    }
    x -= y;
    x = (x+MOD)%MOD;
    x -= y;
    x = (x+MOD)%MOD;
    x +=z;
    x %= MOD;
    x = (x+MOD)%MOD;
    cout << x << endl;
}