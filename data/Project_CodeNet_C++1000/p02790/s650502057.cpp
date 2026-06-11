
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    if(n<m){
    for(int i=0;i<m;i++)
        cout<<n;
     }
    else{
        for(int i=0;i<n;i++)
        cout<<m;
    }
    cout<<"\n";

    return 0;
}
