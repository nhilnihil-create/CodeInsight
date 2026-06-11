#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
using namespace std;

int main()
{
    int a,b;
    int v,w;
    int t;
    cin>>a>>v;
    cin>>b>>w;
    cin>>t;
    long long int  l=abs(a-b);
    int  v1=v-w;
    if(v1<=0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        if(l*1.0/v1<=t)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
