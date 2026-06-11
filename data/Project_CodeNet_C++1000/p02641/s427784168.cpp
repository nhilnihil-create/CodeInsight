#include <bits/stdc++.h>
using namespace std;
int main(){
int x,n,o=0,k,p;
cin>>x>>n;
int z=x+1,l=x-1;
int y[n];
if (n==0)
    cout<<x;
else{
for(int i=0;i<n;i++)
cin>>y[i];
sort(y,y+n);
for(int i=0;i<n;i++){
if(x!=y[i])
o++;
else{
k=p=i;
break;}
}
int u;
if(n-k>=k)
    u=k;
else
    u=n-k;
if (o==n)
cout<<x;
else
for(int i=0;i<n;i++){
k--;
p++;
if(y[k]!=l){
cout<<l;
i++;
break;
}
else if(y[p]!=z){
cout<<z;
i++;
break;}
else{
z++;
l--;
}
}
}
return 0;
}
