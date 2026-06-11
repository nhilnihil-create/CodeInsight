#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int b[100];
    int ans=0;
    rep(i,n-1) {
        cin>>b[i];
    }
    vector<int> c(n,-1);
    rep(i,n-1){
        if(i!=n-2){
            if(b[i]<=b[i+1]){
                //cout<<c[i]<<endl;
                if(c[i]==-1) c[i]=b[i];
                c[i+1]=b[i];
                //cout<<1<<endl;
            }else{
                //cout<<c[i]<<endl;
                if(c[i]==-1) c[i]=b[i];
                //cout<<2<<endl;
            }
        }else{
            if(c[i]==-1) c[i]=b[i];
            c[i+1]=b[i];
        }
        //cout<<c[i]<<endl;
    }
    rep(i,n) {
        ans+=c[i];
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}