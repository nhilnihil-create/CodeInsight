#include <bits/stdc++.h>
using namespace std;
int main(){
string x,y,l,n;
cin>>x;
int z=0;
 y=x;
 l=x;
 n=x;
int o,j,a,s;
o=x.size()-1;
j=x.size()-1;
a=(x.size()-1)/2-1;
s=(x.size()+3)/2-1;
for(int i=0;i<j;i++){
    swap(x[j],x[i]);
    j--;
}
if(x==y){
    z++;}

    for(int i=0;i<=a;i++){
            if(a==1){
            break;
    z++;
    }
    swap(l[a],l[i]);
    a--;
}
if(l==y){
    z++;}

for(;s<o;s++){
    swap(n[o],n[s]);
    o--;
}
if(n==y){
    z++;}

if (z==3)
cout<<"Yes";
else
cout<<"No";
return 0;
}
