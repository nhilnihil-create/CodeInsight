#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n,ans=0;
    cin>>n;
    rep(i,n){
        int a;
        cin>>a;
        if(a!=i+1) ans++;
    }
    if(ans<=2) cout<<"YES";
    else cout<<"NO";
}