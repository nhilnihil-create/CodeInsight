#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    int aa;
    rep(i,n){
        cin>>aa;
        a[i]=aa;
        b[i]=aa;
    }
    sort(b.begin(),b.end());
    int b0=b[n-1];
    int b1=b[n-2];
    rep(i,n){
        if(a[i]==b0) cout<<b1<<endl;
        else cout<<b0<<endl;
    }
}