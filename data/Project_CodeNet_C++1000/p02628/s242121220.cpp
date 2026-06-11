#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e5+5;
int a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1;i<=m;i++){
      sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}