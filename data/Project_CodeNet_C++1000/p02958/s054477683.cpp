#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
#define ll long long int
#define test_case int t,i;cin>>t;for(i=0;i<t;i++)
using namespace std;

int main()
{
    int n,i,x,c=0;
    cin>>n;

    vector<int>a;
    vector<int>sorted;

    for (i=0; i<n; i++)
    {
        cin>>x;
        a.push_back(x);
        sorted.push_back(x);
    }

    sort(sorted.begin(),sorted.end());
    
    for(i=0; i<n; i++)
    {
        if(a[i]!=sorted[i])
            c++;
    }

    if (c==2 || c==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}
