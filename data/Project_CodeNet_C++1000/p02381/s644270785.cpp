#include<bits/stdc++.h>
using namespace std;

int main(){
cout<<fixed<<setprecision(12);

int n;
while(cin>>n){
if(n==0){break;}
double a[n];
double al=0;
for(int i=0;i<n;i++){
cin>>a[i];
al+=a[i];
}

al=al/n;
double bun=0;
for(int i=0;i<n;i++){
bun+=(a[i]-al)*(a[i]-al)/n;
}

cout<<sqrt(bun)<<endl;
}

return 0;
}
