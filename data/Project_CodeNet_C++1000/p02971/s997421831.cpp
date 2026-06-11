#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int x[n],y[n],z[n];
for(int i=0;i<n;i++){
cin>>x[i];
z[i]=x[i];
}
sort(x,x+n);
for(int i=0;i<n;i++){
if(z[i]==x[n-1])
cout<<x[n-2]<<endl;
else cout<<x[n-1]<<endl;
}
return 0;
}
