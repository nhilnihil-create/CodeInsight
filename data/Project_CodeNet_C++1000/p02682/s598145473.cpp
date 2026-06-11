#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int sum = 0;
    if(k>=a){
        sum += a;
        k-=a;
    }else{
        cout<<k<<endl;
        return 0;
    }

    if(k>=b){
        k-=b;
    }else{
        cout<<a<<endl;
        return 0;
    }

    if(k>=c){
        sum -= c;
    }else{
        sum -= k;
    }
    cout<<sum<<endl;
}