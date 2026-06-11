#include<bits/stdc++.h>
using namespace std;
int main(){
        ios_base::sync_with_stdio(false); cin.tie(0);
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w", stdout);
        int n,xo=0; cin>>n;
        int a[n] ; for(int i=0;i<n;i++) {cin>>a[i]; xo^=a[i]; }
        for(int i=0;i<n;i++) cout<<(xo^a[i])<<" ";
        cout<<endl;
}

