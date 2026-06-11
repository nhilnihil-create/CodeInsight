#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e5+5, M = 1e6+6, OO = 0x3f3f3f3f;
int tc;
ll arr[N];
int main()
{
    FIO
    ll x = 0;
    int n; cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        cin>>arr[i];
        x ^= arr[i];
    }
    for(int i = 0 ; i<n ; i++)
        cout<< (arr[i]^x) <<" ";
    return 0;

}