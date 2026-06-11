#include <bits/stdc++.h>
using namespace std;
int main(void){int n,m=1e9+7,i;long long ans=1;cin>>n;vector<int> a(n),c(n+1,0);for(i=0;i<n;i++)cin>>a[i],++a[i];c[0]=3;for(int x:a)(ans*=c[x-1]-c[x])%=m,++c[x];cout<<ans<<endl;return 0;}
