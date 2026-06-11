/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back

#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 5000000
int dirx[] = {1, -1,0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};



//=============================================ASIFAZAD==============================================//

vi ck(N+7);

void seive()
{
    for(int i = 3; i*i <= N; i+=2)
        if(ck[i] == 0)
            for(int j = i*i; j<= N; j+= 2*i)
                ck[j] = 1;
    ck[1] = 1;
    for(int i = 4; i<= N; i+= 2)
        ck[i]  = 1;
}
int32_t main()
{
    io;
    seive();
//    for(auto x: ck) cout<<x<<"\n";
    int x;
    cin>>x;
    for(; ; x++)
        if(ck[x] == 0)
            break;
    cout<<x;
    return 0;
}

