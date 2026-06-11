#include <bits/stdc++.h>
//deeply ingrained
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n && k--;i++) {
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
