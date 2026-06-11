#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    long h;
    long ma=0;
    rep(i,n){
        cin>>h;
        if(h<(ma-1)){
            cout<<"No"<<endl;
            return 0;
        }
        ma=max(ma,h);
    }
    cout<<"Yes"<<endl;
}