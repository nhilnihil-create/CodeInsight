#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin>>n>>k;
    int up=(n-1)*(n-2)/2;
    if(k>up)
         cout<<"-1";
    else{
        int m=n-1+(n-1)*(n-2)/2-k;
        cout<<m<<"\n";
        for(int i=2; i<=n; i++)
             cout<<"1 "<<i<<"\n";
        int cnt=(n-1)*(n-2)/2-k;
        for(int i=2; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(cnt==0)
                    break;
                else{
                    cnt--;
                    cout<<i<<" "<<j<<"\n";
                }
            }
        }
    }
    return 0;
    
}