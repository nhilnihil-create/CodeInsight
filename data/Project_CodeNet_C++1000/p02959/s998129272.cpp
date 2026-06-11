#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<long> a(n+1);
    long b;
    long ans=0;
    rep(i,n+1){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b;
        long a1=a.at(i);
        long aa=a.at(i+1);
        if(a1+aa<=b){
            ans=ans+a1+aa;
            a[i]=0;
            a[i+1]=0;
        }else if(a1<=b){
            ans+=b;
            a[i]=0;
            a[i+1]=aa-(b-a1);
        }else{
            ans+=b;
            a[i]=a1-b;
        }
    }
    cout<<ans<<endl;
}