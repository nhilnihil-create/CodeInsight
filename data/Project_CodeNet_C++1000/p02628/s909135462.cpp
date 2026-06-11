#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    long long sm=0;
    vector <int>v;

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k;i++){
        sm+=v[i];
    }
    cout << sm << endl;
    return 0;
}
