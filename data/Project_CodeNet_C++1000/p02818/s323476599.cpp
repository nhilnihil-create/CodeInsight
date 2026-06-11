#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    long a, b, k;
    cin>>a >>b >>k;
    if(a>=k) cout<<a-k<<" "<<b<<endl;
    else if(a+b>=k) cout<<0<<" "<<a+b-k<<endl;
    else cout<<"0 0"<<endl;
}