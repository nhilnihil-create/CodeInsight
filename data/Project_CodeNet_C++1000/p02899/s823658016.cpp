#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int x[n],y[n];
for (int i=1;i<n+1;i++){
cin>>x[i];
y[x[i]]=i;
}
for (int i=1;i<n+1;i++){
cout<<y[i]<<" ";
}
return 0;
}
