#include<bits/stdc++.h>
using namespace std;
int main(){int a,b,m,i,ma=100000,mb=100000,ans,l,r,c;
cin>>a>>b>>m;
int A[a+1],B[b+1];
for(i=1;i<=a;i++){cin>>A[i];
    ma=min(ma,A[i]);
}
for(i=1;i<=b;i++){cin>>B[i];
    mb=min(mb,B[i]);
}
ans=mb+ma;
while(m--){
    cin>>l>>r>>c;
    ans=min(ans,A[l]+B[r]-c);
}
cout<<ans;
    return 0;}
