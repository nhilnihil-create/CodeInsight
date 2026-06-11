#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int a, b;
    cin>>a >>b;
    if(b==1){
        cout<<0<<endl;
        return 0;
    }
    if(a>=b){
        cout<<1<<endl;
        return 0;
    }
    for(int i=2;i<b;i++){
        if(a*i-(i-1)>=b){
            cout<<i<<endl;
            return 0;
        }
    }
}