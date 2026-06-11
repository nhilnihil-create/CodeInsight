#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = 998244353;
const double PI = 3.141592653589793238463;
const int MAXN = 200005;

int main()
{
    FAST
    int k;
    cin>>k;
    if(k%2==0)
        return cout<<-1,0;
    ll f=7;
    ll cnt=1;
    while(true){
    if(f%k==0)
        return cout<<cnt,0;
        if(cnt>k)
            return cout<<-1,0;
    f=(f%k)*10+7;
    cnt++;

    }


    return 0;
}
