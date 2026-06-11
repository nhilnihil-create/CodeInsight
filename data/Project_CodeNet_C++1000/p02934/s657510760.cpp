#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    cin>>N;
    int A;
    double r=0.00000;
    rep(i,N){
        cin>>A;
        r+=1.00000/A;
    }
    double ans=1/r;
    cout<<ans<<endl;
}
