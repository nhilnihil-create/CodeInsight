#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int a[200010];
    a[1]=1;
    int ans[200010]={0};
    for(int i=1;i<n;i++){
        cin>>a[i+1];
        ans[a[i+1]]++;
    }
    rep(i, n){
        cout<<ans[i+1]<<endl;
    }
}