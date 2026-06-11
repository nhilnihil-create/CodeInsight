#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    long n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
    }else{
        cout<<n*(n-1)/2<<endl;
    }
}