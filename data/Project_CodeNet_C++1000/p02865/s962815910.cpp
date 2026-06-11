#include <bits/stdc++.h>
#define inf 2e18
using namespace std;
typedef long long ll;
typedef pair<ll,ll>p;
ll a[100005],b[100005];
int main()
{
    //freopen("in.txt", "r", stdin);
    ll n;
    cin>>n;
    if(n&1){
        cout<<n/2<<endl;
    }
    else{
        cout<<n/2-1<<endl;
    }
}

