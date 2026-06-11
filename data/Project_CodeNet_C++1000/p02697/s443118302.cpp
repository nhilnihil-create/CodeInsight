#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    cin >>n>>m;
    if(n%2==1){
    for(int i=1;i<=m;i++){
    cout<<i<<" "<<n+1-i<<endl;
    }
    }
    else{
    for(int i=1;i<=m&&i<=n/4;i++){
    cout<<i<<" "<<n+1-i<<endl;
    }
    if(m>n/4) {
        for(int i=n/4+1;i<=m;i++){
            cout<<i<<" "<<n-i<<endl;
        }
    }
    }



}
