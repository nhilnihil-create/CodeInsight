#include<iostream>
#include<map>
using namespace std;
int n,a[200010];
long long ans;
map<int,int> myd;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        ans+=myd[i-a[i]];
        myd[i+a[i]]++;
    }
    printf("%lld",ans);
}