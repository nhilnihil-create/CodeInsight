#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t a,b,c; cin>>a>>b>>c;


    string ans="No";
    // a+2(ab)^(1/2)+b<c <=> 4bc<(c-a-b)^2
    int64_t l=4*a*b, r=a*a+b*b+c*c+2*a*b-2*b*c-2*c*a;
    if(c-a-b>0 && l<r) ans="Yes";

    cout<<ans<<endl;
}