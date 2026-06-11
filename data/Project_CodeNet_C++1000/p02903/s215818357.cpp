#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W,A,B; cin>>H>>W>>A>>B;

    rep(h,0,H){
        rep(w,0,W){
            if(h<B){
                if(w<A) cout<<1;
                else cout<<0;
            }else{
                if(w>=A) cout<<1;
                else cout<<0;
            }
        }
        cout<<endl;
    }
}