#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t,j,p,r,i;
    cin>>j>>t;
    p=t-j+1;
    if(p<-1000000)
    p=-1000000;
    r=t+j-1;
    if(r>1000000)
    r=1000000;
    for(i=p;i<=r;i++)
    cout<<i<<" ";
    return 0;
}
