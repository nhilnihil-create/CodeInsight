#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    if(n&1)cout<<"No";
    else{
          bool ok =true;

        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n/2+i])ok=false;
        }
        if(!ok)cout<<"No";
        else cout<<"Yes";

    }


    return 0;
}
