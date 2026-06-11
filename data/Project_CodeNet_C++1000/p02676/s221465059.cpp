#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a,c;
    string b;
    cin>>a;
    cin>>b;
    c = b.size();
    if(c > a){
        b.resize(a);
        cout<<b<<"..."<<endl;
    }
    else{
        cout<<b;
    }

    return 0;
}
