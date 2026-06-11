#include <bits/stdc++.h>
#define rep(i,l,r) for(int (i)=(l);(i)<(r);(i)++)
#define ll long long
using namespace std;
void deb(){
    cout<<"a";
    exit(0);
}
ll fp(ll a){return a*a*a*a*a;}
int main(){
    ll x;
    cin>>x;
    rep(a,-120,121){
        rep(b,-120,121){
            if(fp(a)-fp(b)==x){
                cout<<a<<" "<<b<<endl;
                return 0;
            }
        }
    }
}