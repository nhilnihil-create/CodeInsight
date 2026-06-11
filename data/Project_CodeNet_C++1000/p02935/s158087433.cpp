#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,i,q;
    cin>>n;
    double a[n],s=0;
    for(i=0;i<n;i++)
        cin>>a[i];
   sort(a,a+n);
   for(i=1;i<n;i++){
       a[i]=(a[i]+a[i-1])/2;
   }cout.precision(9);
   cout<<fixed<<a[n-1];
return 0;
}
