#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    int a,b,m;
    cin >> a >> b >> m;
    vector<int> A(a);
    vector<int> B(b);
    vector<int> x(m);
    vector<int> y(m);
    vector<int> c(m);

    rep(i,a){
        cin >> A[i];
    }
    rep(i,b){
        cin >> B[i];
    }
    rep(i,m){
      cin >> x[i] >> y[i] >> c[i];
    }
    
    int ans=1000000;
    
    rep(i,m){
        ans=min(ans,A[x[i]-1]+B[y[i]-1]-c[i]);
    
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

 ans=min(ans,A[0]+B[0]);

    cout << ans << endl;

    return 0;

}