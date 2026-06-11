#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i;
    cin>>n>>m;
    if(n>m){
        for(i=1;i<=n;i++){
            cout<<m;
        }
    }
    else if(n<m){
        for(i=1;i<=m;i++){
            cout<<n;
        }
    }
    else
        for(i=1;i<=n;i++){
            cout<<n;
        }
}
