#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n, d;
    cin>>n >>d;
    rep(i,n+1){
        if((2*d+1)*i>=n){
            cout<<i<<endl;
            return 0;
        }
    }
}