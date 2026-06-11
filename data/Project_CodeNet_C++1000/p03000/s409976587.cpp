#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


signed main(){
    FAST;
    int n, x;
    cin>>n>>x;
    int a[n+1], s=0;
    a[0]=0;
    for(int i=1; i<=n; i++) {
        int k;
        cin>>k;
        s+=k;
        a[i]=s;
    }
    int c=0;
     for(int i=0; i<=n; i++) if(a[i]<=x) c++;
     cout<<(c==0 ? 1: c);
}

