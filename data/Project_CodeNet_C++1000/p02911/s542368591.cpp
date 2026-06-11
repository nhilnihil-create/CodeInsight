#include <bits/stdc++.h>
using namespace std;

int main(){
    long long  n,k,q,a,ans[100000]={};
    cin>>n>>k>>q;
    for(int i=0;i<n;i++) ans[i]=k-q;
    for(int i=0;i<q;i++){
        cin>>a;
        a--;
        ans[a]++;
    }
    for(int i=0;i<n;i++){
        if(ans[i]>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}