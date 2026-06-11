#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int a,b;
    cin>>a>>b;
    rep(i,1000+1){
        if(i*8/100 == a && i*10/100 == b){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}