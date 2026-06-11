#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll t1,t2,a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    a1*=t1;
    b1*=t1;
    a2*=t2;
    b2*=t2;
    if(a1+a2<b1+b2){
        swap(a1,b1);
        swap(a2,b2);
    }
    if(a1+a2==b1+b2){cout<<"infinity"<<endl; return 0;}
    if(a1>b1){cout<<0<<endl; return 0;}
    ll c=b1-a1;
    ll d=(a1+a2)-(b1+b2);
    ll ans=(c/d+1)*2-1;
    if(c%d==0)ans--;
    cout<<ans<<endl;
}