#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef LOCAL_EXEC
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif // LOCAL_EXEC
    long long int n,i,j,k,x=0,y;
    cin>>n;
    for(i=1;i<=n-1;i++){
        x+=(n-1)/i;
    }
    cout<<x;
    return 0;
}
