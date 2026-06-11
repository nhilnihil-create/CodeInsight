#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n==m){
        for(int i=0;i<n;i++){
            cout<<n;
        }
       cout<< endl;
    }
    else{
        int v=min(m,n);
        int c=max(m,n);
        for(int i=0;i<c;i++){
            cout<<v;
        }
        cout<<endl;
    }
    return 0;
}
