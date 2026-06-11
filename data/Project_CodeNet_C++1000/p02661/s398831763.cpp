#include<bits/stdc++.h>
using namespace std;
main(){
    int n;cin>>n;
    int a[n],b[n]; for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    sort(a,a+n),sort(b,b+n);
    n&1?cout<<b[n/2]-a[n/2]+1:cout<<(b[n/2]+b[n/2-1])-(a[n/2]+a[n/2-1])+1;
}
