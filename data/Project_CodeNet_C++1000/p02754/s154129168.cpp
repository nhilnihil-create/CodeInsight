// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    long long int n,a,b,c,m,k,ans=0;
    cin >> n >> a >> b;
    c=n%(a+b);
    m=n-c;
    k=m/(a+b);
    ans=k*a;
    if(c>=a)
    {
        ans+=a;
    }
    else
    {
        ans+=c;
    }
    

    

    cout << ans << endl;

}
