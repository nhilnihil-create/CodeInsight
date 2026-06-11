// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j,zero=0;
    long long int ans=0,m=1,a[200010];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
        zero++;
        }
    }
    if(zero>0)
    {
        cout << 0 << endl;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(a[i]<=1000000000000000000/m)
        {
            m*=a[i];
        }
        else
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    
    
    

    cout << m << endl;
    

    

}
