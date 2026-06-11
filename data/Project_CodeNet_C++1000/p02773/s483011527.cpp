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
#define pb push_back
#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 110
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};


//=============================================ASIFAZAD==============================================

int32_t main()
{
    io;
    int n;
    cin>>n;
    map<string, int> cnt;
    int mx = 0;
    for(int i =0 ; i< n;i++)
    {
        string s;
        cin>>s;
        cnt[s]++;
        mx = max(mx, cnt[s]);
    }
    for(auto a: cnt)
        if(a.second == mx)
            cout<<a.first<<"\n";
    return 0;
}