#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
long long n,h,j,i,x,y,c=0,m,p;
cin>>n>>h;
vector<long long>a;
vector<long long>b(n);
for(i=0;i<n;i++){
        cin>>j;
        a.push_back(j);
}
for(i=0;i<h;i++){
    cin>>m>>p;
    x=m-1;
    y=p-1;
if(a[x]==a[y]){
    b[x]=1;
    b[y]=1;
}
else if(a[x]>a[y]){
    b[y]=1;
}
else{
    b[x]=1;
}
}
for(i=0;i<n;i++){
    if(b[i]==0){
        c++;
    }
}
cout<<c;
}
