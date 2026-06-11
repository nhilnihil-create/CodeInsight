// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int i,j,len,lenr,lenp;
    string s,m,m2,n,m3,n2;
    cin >> s;
    len=s.size();
    lenr=(len-1)/2;
    m=s;
    m2=s.substr(0,lenr);
    n=m2;
    m3=s.substr((len+3)/2-1,lenr);
    n2=m3;
    
    reverse(m.begin(), m.end());
    reverse(n.begin(), n.end());
    reverse(n2.begin(), n2.end());
        if(s!=m || m2!=n || m3!=n2)
        {
            cout << "No" << endl;
            return 0;
        }
    
    

    cout << "Yes" << endl;
    

    

}
