#include<bits/stdc++.h>
using namespace std;
long long n, a[200005], b[200005], c[200005], d[200005];
int main(){
       cin>>n;
       for(long long i=1; i<=n; i++){
              cin>>a[i]>>b[i];
              c[i]=a[i]+b[i];
              d[i]=(a[i]-b[i]);
       }
       sort(c+1, c+n+1);
       sort(d+1, d+n+1);
       cout<<max(c[n]-c[1], d[n]-d[1]);
       return 0;
}