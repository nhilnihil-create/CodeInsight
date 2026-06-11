#include <bits/stdc++.h>
using namespace std;
long long n,x,t,m,k;
int main(){
cin>>n>>x>>t;
m=t;
k=x;
while(k<n){
    m+=t;
    k+=x;
}
cout<<m;

    return 0;}
