#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int k,n;
    cin>>k>>n;
    int dis=-1;
    int a[200010];
    rep(i, n){
        cin>>a[i];
        if(i!=0){
            int tmp=a[i]-a[i-1];
            dis=max(dis,tmp);
        }
    }
    int tmp=k+a[0]-a[n-1];
    dis=max(dis,tmp);
    cout<<k-dis<<endl;
}