#include <bits/stdc++.h> 
using namespace std; 
int main(){
int n;

double res,part=0;
cin>>n;
double a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    part=part+(1/a[i]);
}
res=1/part;
cout<<res<<endl;
    

    return 0;
}
