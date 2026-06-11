#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long X,K,D;
    cin>>X>>K>>D;
    X=abs(X);
    if(X/D>=K)
    {
        cout<<X-K*D<<endl;
        return 0;
    }
    K-=(X-(X%D))/D;
    X%=D;
    if(K%2==0) cout<<X<<endl;
    else cout<<abs(X-D)<<endl;
    return 0;
}
