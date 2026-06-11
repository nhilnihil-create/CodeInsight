#include<bits/stdc++.h>
using namespace std;
 int a[200010];
 int b[200010];
 int main(){
 int n;
 scanf("%d",&n);
 for(int i=2;i<=n;i++)scanf("%d",&a[i]);
 for(int i=2;i<=n;i++)b[a[i]]++;
 for(int i=1;i<=n;i++)printf("%d\n",b[i]);
return 0;
}
