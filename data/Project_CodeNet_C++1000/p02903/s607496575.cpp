#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll h,w,a,b;cin>>h>>w>>a>>b;
    a--;b--;
    rep(i,0,h){
        rep(j,0,w){
            if(i<=b){
            if(j<=a)cout<<0;
            else cout<<1;
            }
            else{
                if(j<=a)cout<<1;
                else cout<<0;
            }
            
        }
        cout<<endl;
    }
}





