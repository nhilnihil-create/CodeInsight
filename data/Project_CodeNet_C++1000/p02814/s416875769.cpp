#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a,long long b){
    return a*b/__gcd(a,b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);

    long long n,m;
    cin>>n>>m;
    vector<long long> v(n);
    long long lc=1ll;
    for(int i=0;i<n;i++){
        long long tm;
        cin>>tm;
        tm/=2ll;
        lc=lcm(lc,tm);
        v[i]=2ll*tm;
    }
    int f1=0,f2=0;
    for(int i=0;i<n;i++){
        if((lc)%v[i]==0ll){
            f1=f2=1;
        }
    }
    if(f1&&f2)
        cout<<0;
    else
        cout<<(m/lc)/2ll+((m/lc)%2ll)<<'\n';
    return 0;
}
/***
4 3 2 3
1 4 1 100
1 2 1 10
1 3 20 1
*/
