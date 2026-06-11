#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int M,D;
    cin>>M>>D;
    int ans=0;
    for(int d = 1;d<=D;d++){
        int d_1 = d%10;
        int d_10 = d/10;
        if(d_1<2 || d_10 <2)
            continue;
        
        if(d_1*d_10 <= M){
            ans++;
        }
    }
    cout<<ans<<endl;
}