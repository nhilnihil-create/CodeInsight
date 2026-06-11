#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int N;cin>>N;
    vector<double>a(N);
    ll sum=0;
    ll seki=1;
    rep(i,N){
        cin>>a.at(i);
        sum+=a.at(i);
        seki*=a.at(i);
    }
    double bunbo=0;
    rep(i,N){
        bunbo+=seki*1.0/a.at(i);
    }
    printf("%.14f\n",seki*1.0/bunbo);
}