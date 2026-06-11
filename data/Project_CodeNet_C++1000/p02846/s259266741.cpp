#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
struct edge {int to,costa,costb;};

signed main() {
int t1,t2,a1,a2,b1,b2,ans;
cin>>t1>>t2>>a1>>a2>>b1>>b2;
if(a1<b1){
    a1*=-1;
    b1*=-1;
    a2*=-1;
    b2*=-1;
}

if((a1-b1)*t1+(a2-b2)*t2>0){
    cout<<0;
    return 0;
}
if((a1-b1)*t1+(a2-b2)*t2==0){
    cout<<"infinity";
    return 0;
}
int x=(a1-b1)*t1,y=(a1-b1)*t1+(a2-b2)*t2;y*=-1;
 ans=2*(x/y);
if(x%y==0){
  cout<<ans;
}else {
    //cerr<<(abs(a1-b1)*t1)%abs(abs(a1-b1)*t1-abs(a2-b2)*t2)<<endl;
    cout<<1+ans;
}


return 0;
}
