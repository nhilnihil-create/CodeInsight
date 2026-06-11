#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    int ans[2100]={0};
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int dis=min(j-i, abs(x-i)+1+abs(y-j));
            ans[dis]++;
        }
    }
    for(int i=1;i<n;i++){
        cout<<ans[i]<<endl;
    }
}