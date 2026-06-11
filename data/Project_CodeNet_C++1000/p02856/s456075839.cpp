#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    int M;cin >> M;
    ll sumd=0,sumc=0;
    ll c,d;
    for (int i=0;i<M;i++)
    {
        cin >> d >> c;
        sumd+=d*c;
        sumc+=c;
    }
    if (sumd%9==0) cout << sumc-1+sumd/9-1 << endl;
    else cout << sumc-1+sumd/9 << endl;
    return 0;
}