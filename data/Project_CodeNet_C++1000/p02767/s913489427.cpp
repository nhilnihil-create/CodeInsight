#include <bits/stdc++.h>
using namespace std;
int a[150];
int n,p,k;

double sum,s;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
    s+=a[i];
}
sort(a,a+n);
sum = round(s/n);
for(int i=0;i<n;i++){
    k=abs(a[i]-sum);
    p+=pow(k,2);
}
cout<<p;

return 0;}

