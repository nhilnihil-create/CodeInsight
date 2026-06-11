#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long v=0,e=0;
    for(int i=1;i<=n;i++)v+=i*(n-i+1);
    long long x[n-1],y[n-1];
    for(int i=0;i<n-1;i++){
        cin>>x[i]>>y[i];
        e+=min(x[i],y[i])*(n-max(x[i],y[i])+1);
    }
    cout<<v-e<<endl;
    return 0;
}
