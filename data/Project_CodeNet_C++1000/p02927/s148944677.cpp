#include<bits/stdc++.h>
using namespace std;
int main(){long long n,l,s=0,p,k,r=1,m,t,j,i;
cin>>n>>k;
if(k<22)
cout<<0;
else{
    for(i=1;i<=n;i++){
        for(j=22;j<=k;j++){r=j;
            m=r%10;
            r=r/10;
            t=r%10;
            if(m*t==i&&m>=2&&t>=2){
            s++;}
        }
    }cout<<s;
}


    return 0;
}
