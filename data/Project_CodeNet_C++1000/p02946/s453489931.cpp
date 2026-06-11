#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int K,X;
    cin>>K>>X;
    int N=X-K+1;
    rep(i,2*K-1){
        if(N>1000000||N<-1000000){
            continue;
        }
        cout<<N+i<<" ";
    }
    cout<<endl;
}
