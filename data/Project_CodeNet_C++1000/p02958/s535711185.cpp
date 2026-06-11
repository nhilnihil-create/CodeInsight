#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include<stdio.h>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define endl "\n"
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

int main()
{
    int i,x,n,j,flag,temp=0;
    cin>>n;
    int a[n];

    for (i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        if(a[i]!=i+1)
        {
            flag=1;
            break;
        }
    }
    for(j=0; j<n; j++)
    {
        if(a[j]==i+1)
        {
            break;
        }
    }
    if (flag==1)
    {
        x=a[i];
        a[i]=a[j];
        a[j]=x;
    }

    for(i=0; i<n-1 ; i++)
    {
        if(a[i]>a[i+1])
        {
            cout<<"NO"<<"\n";
            temp=1;
            break;
        }
    }
    if (temp==0)
        cout<<"YES"<<"\n";
    return 0;
}

