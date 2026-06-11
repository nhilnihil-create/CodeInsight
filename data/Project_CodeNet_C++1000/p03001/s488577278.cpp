#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    long w, h, x, y;
    cin>>w >>h >>x >>y;
    if(w%2==0 || h%2==0){
        if(x*2==w && y*2==h){
            cout<<w*h/2<<" "<<1<<endl;
        }else{
            cout<<w*h/2<<" "<<0<<endl;
        }
    }else{
        cout<<w*h/2<<".5 "<<0<<endl;
    }
}