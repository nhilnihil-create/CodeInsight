//
// Created by 10034 on 2020/7/28.
//

#include <iostream>
using namespace std;
const int N=200010;
int u[N],v[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        cin>>u[i]>>v[i];
    }
    long long res=0;
    for(int i=1;i<=n;++i){
        res=res+(long long )(n-i+1)*i;
    }
    for(int i=1;i<n;++i){
        if(u[i]>v[i]) swap(u[i],v[i]);
        res=res-(long long )u[i]*(n-v[i]+1);
    }
    cout<<res<<endl;

    return 0;
}