#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int from1=(n-1)*(n-2)/2;
    if(from1<k){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<n+from1-k-1<<endl;
    k=from1-k;
    for(int i=2;i<=n;i++)cout<<1<<" "<<i<<endl;
    bool br=0;
    for(int i=2;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(k==0){
                br=1;
                break;
            }
            cout<<i<<" "<<j<<endl;
            k--;
        }
        if(br)break;
    }
    return 0;
}