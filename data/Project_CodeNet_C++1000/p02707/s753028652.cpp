#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n-1];
    for(int i=0;i<n-1;i++) cin>>a[i];
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    for(int i=0;i<n-1;i++){
        int num=a[i];
        ans[num-1]++;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}