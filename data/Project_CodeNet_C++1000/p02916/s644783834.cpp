#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    int n;
    cin>>n;
    vector<int> A(n),C(n-1);
    rep(i,n) cin>>A[i];
    int sum=0;
    rep(i,n){
        int b;
        cin>>b;
        sum+=b;
    }
    rep(i,n-1) cin>>C[i];
    rep(i,n-1) if(A[i]+1==A[i+1]) sum+=C[A[i]-1];
    cout<<sum<<endl;
    return 0;
}