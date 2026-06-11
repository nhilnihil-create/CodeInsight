#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    while(k--){
        int b[n]={0},m=2*n;
        for(int i=0;i<n;i++){
            m=min(m,a[i]);
            b[max(0,i-a[i])]++;
            if(i+a[i]+1<n) b[i+a[i]+1]--;
        }
        if(m>=n) break;
        for(int i=0;i<n-1;i++) b[i+1]+=b[i];
        memcpy(a,b,sizeof(b));
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
