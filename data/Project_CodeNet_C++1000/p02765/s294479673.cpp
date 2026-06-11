#include<bits/stdc++.h>
using namespace std;

int main()
{
    typedef long int l;
    l n,r; cin>>n>>r;
    if(n>10){
        cout<<r<<endl;
    }
    else{
        l a=(10-n);
        l b=100*a;
        cout<<r+b<<endl;
    }

}
