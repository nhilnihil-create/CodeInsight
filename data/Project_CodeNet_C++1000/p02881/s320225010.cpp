#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    ll res=N;

    for(ll a=1;a*a<=N;a++){
        if(N%a==0)res=min(res,a+N/a-2);
    }
    cout<<res;
    return 0;
}