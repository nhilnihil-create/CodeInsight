#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,w[105];
    long long sum1=0,sum2=0,ans=0x3f3f3f3f3f3f3f3f;
    cin>>n;
    for (int i=0; i<n; i++) {cin>>w[i]; sum2+=w[i];}
    for (int i=0; i<n; i++) {
        ans=min(ans,abs(sum2-sum1));
        sum2-=w[i]; sum1+=w[i];
    }
    ans=min(ans,abs(sum2-sum1));
    cout<<ans<<'\n';
}