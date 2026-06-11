#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
int i,j,k,d,n,m,c=0;
cin>>n>>k;
vector<int>a(n+1);
for(i=0;i<k;i++){
    cin>>d;
    for(j=0;j<d;j++){
        cin>>m;
        a[m]++;
    }
}
for(i=1;i<=n;i++){
    if(a[i]==0)
        c++;
}
cout<<c;
}
