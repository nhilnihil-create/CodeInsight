#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int arr[200010];

int main()
{
    int k,n;
    int flag;

    cin>>k>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    flag=arr[0]+k-arr[n-1];

    for(int j=0; j<n; j++)
    {
        flag=max(flag,arr[j+1]-arr[j]);

    }
    cout<<k-flag<<endl;
    return 0;
}

