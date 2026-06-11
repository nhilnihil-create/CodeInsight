#include<bits/stdc++.h>
#include <iostream>
#include <list>
#define ll long long int
using namespace std;
int main()
{
    int a; cin>>a;
    int i,m;
    for(i=1;i<=9;i++)
    {
        if(a%i==0)
        {
            if(a/i<=9) {m=1;break;}
            else m=0;
        }
    }
    if(m)cout<<"Yes\n";
    else cout<<"No\n";
}

