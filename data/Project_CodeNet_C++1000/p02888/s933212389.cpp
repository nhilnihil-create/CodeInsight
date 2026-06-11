#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
int n,a[2005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+1+n);

    int ans=0;

    for(int i=1;i<=n-2;i++)
    for(int j=i+1;j<n;j++){
        int p =lower_bound(a+j,a+1+n,a[i]+a[j])-a;
            ans+=p-j-1;
    }
    printf("%d\n",ans);


    return 0;
}

