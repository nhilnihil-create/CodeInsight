#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int mgcd(int a,int m){
    if(m==0) return a;
    return mgcd(m,a%m);
}

int mlcm(int x,int y){
    return x*y/mgcd(x,y);
}

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    sort(A.begin(),A.end());
    int lcm=A[0];
    rep(i,n-1) lcm=mlcm(lcm,A[i+1]);
    double under=0;
    rep(i,n) under+=(double)lcm/A[i];
    cout<<fixed<<setprecision(10)<<lcm/under<<endl;
    return 0;
}