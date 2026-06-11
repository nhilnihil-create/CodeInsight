#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int k, x;
    cin>>k >>x;
    rep(i,k){
        cout<<x-k+1+i<<" ";
    }
    for(int i=1;i<k;i++){
        cout<<x+i<<" ";
    }
    cout<<endl;
}