#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    int A,B,m;
    cin >> A >> B >> m;
    VI a(A);
    VI b(B);
    rep(i,A)cin >> a.at(i);
    rep(i,B)cin >> b.at(i);
    VI x(m),y(m),c(m);
    rep(i,m){
        cin >> x.at(i) >> y.at(i) >> c.at(i);
    }
    ll ans=mm;
    rep(i,m){
        int X=a.at(x.at(i)-1);
        int Y=b.at(y.at(i)-1);
        ll cst=X+Y-c.at(i);
        ans=min(ans,cst);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll cst=a.at(0)+b.at(0);
    ans=min(ans,cst);
    cout << ans << endl;

}



    
   
