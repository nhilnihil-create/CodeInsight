#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int n,s;
    cin>>n>>s;
    int sm=0;
    for(int i=1;i<=s;i++){
        int x;
        cin>>x;
        sm+=x;
    }
    cout<<max(-1LL,n-sm);
}
