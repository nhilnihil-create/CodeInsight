#include<bits/stdc++.h>
using namespace std;
int a[505][505],n;
void solve(int l,int r,int num){
    if(l==r) return;
    int mid=(l+r)/2;
    for(int i=l;i<=mid;i++){
        for(int j=mid+1;j<=r;j++){
            a[i][j]=num;
        }
    }
    solve(l,mid,num+1);
    solve(mid+1,r,num+1);
}
int main(){
    cin>>n;
    solve(1,n,1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}