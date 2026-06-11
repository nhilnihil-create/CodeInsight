#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){//愚直にやってみたら
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    double under=0;
    rep(i,n) under+=(double)1/A[i];
    cout<<fixed<<setprecision(10)<<1/under<<endl;
    return 0;
}