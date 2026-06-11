#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int n;
    cin>>n;
    vector<int> D(n);
    int sum=0;
    rep(i,n){
        cin>>D[i];
        sum+=D[i];
    }
    long long ans=0;
    rep(i,n) ans+=D[i]*(sum-D[i]);
    cout<<ans/2<<endl;
    return 0;
}