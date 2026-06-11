/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back+

#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 3007
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};


//=============================================ASIFAZAD==============================================//

int32_t main()
{
    ll n;
    cin>>n;
    int p = floor(log2(n)) + 1;
    ll ans = 1;
    while(p--)
        ans *= 2;
    ans--;
    cout<<ans;
    return 0;
}
