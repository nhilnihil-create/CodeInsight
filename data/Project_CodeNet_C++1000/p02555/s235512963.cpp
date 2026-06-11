#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=2e3+5;
const int mod=1e9+7;
int d[maxm];
int n;
signed main(){
    cin>>n;
    d[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i-3;j++)
		{
            d[i]+=d[j];
            d[i]%=mod;
        }
    }
    cout<<d[n]<<endl;
    return 0;
}
