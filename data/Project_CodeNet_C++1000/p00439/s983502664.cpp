#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,n2[100001],n_sum[100001];
    while(1){
    cin>>n>>k;
    if(n==0&&k==0)return 0;
    for(int i=0;i<n;i++){
        cin>>n2[i];
    }
    n_sum[0]=0;
    for(int i=1;i<=n;i++){
        n_sum[i]=n_sum[i-1]+n2[i-1];
    }
    int maxx=-10000001;
    for(int i=k-1;i<n;i++){
        int sum=0;
        sum=n_sum[i]-n_sum[i-k];
       // cout<<sum<<endl;
        maxx=max(maxx,sum);
    }
    cout<<maxx<<endl;
    }
}