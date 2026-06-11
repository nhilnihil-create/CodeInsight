#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <vector>
#include <iomanip>
#define rep(i,n) for(int i=0;i<(n);++i)

using namespace std;

typedef long long ll;




int main(){

    int N,K;
    cin>>N>>K;
    double tmp;
    double s[N+1];
    double ans=0;
    s[0]=0;
    for(int i=1;i<=N;++i){
        cin>>tmp;
        s[i]=s[i-1]+(1+tmp)/2.0;
    }

    for(int i=K;i!=N+1;++i){
        ans=ans>=s[i]-s[i-K]?ans:s[i]-s[i-K];
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}